from flask import Flask, request, jsonify
from flask_cors import CORS
import vt
from dotenv import load_dotenv
import os
import asyncio
import modelSUS as model

app = Flask(__name__)
CORS(app)

@app.route('/analyze', methods=['POST'])
def analyze_url():
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    
    url = request.json['url']
    
    is_valid = model.is_valid_url(url)
    client = vt.Client(str(os.getenv("APIKEY")))
    
    try:
        info = client.get_object("/urls/{}".format(vt.url_id(url)))
        analysis_dict = {
            'reputation': info.reputation,
            'votes': info.total_votes.data,
            'analysis': info.last_analysis_stats.data,
        }
    except vt.error.APIError as e:
        if e.args[0] == 'NotFoundError':
            analysis_dict = {
                'reputation': 0,
                'votes': 0,
                'analysis': {'harmless': 0, 'malicious': 0, 'suspicious': 0, 'undetected': 1}
            }
        else:
            raise e

    analysis = model.analyze_url(url)
    result = {
        'is_valid': is_valid,
        'last_analysis_stats': analysis_dict,
        'analysis': analysis
    }
    
    client.close()
    loop.close()
    return jsonify(result)

if __name__ == '__main__':
    load_dotenv()
    app.run()