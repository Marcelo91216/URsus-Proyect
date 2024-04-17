import vt
from dotenv import load_dotenv
import os
import sys

load_dotenv()

url = str()
if len(sys.argv)<2:
    print("Por favor introduzca un valor")
    # check if api key exists
elif 'APIKEY' in os.environ:
    url = sys.argv[1]
    # connection to API with a client
    try:
        client = vt.Client(str(os.getenv('APIKEY')))
        
        # get information about an URL
        info = client.get_object("/urls/{}".format(vt.url_id(url)))
        print(info.last_analysis_stats)

        analysis = client.scan_url(url)
        print(analysis)

        client.close() # always close session
    except NameError:
        print(NameError)
