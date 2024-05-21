# main.py
import vt
from dotenv import load_dotenv  
import os
import sys
import model

load_dotenv()

url = str()
if len(sys.argv)<2:  
    print("Por favor introduzca un valor")
elif 'APIKEY' in os.environ:
    url = sys.argv[1]
    try:
        client = vt.Client(str(os.getenv('APIKEY')))
        
        info = client.get_object("/urls/{}".format(vt.url_id(url)))
        print(info.last_analysis_stats)

        analysis = client.scan_url(url)  
        print(analysis)

        is_valid = model.is_valid_url(url)
        print(f"La URL es {'válida' if is_valid else 'inválida'} según el validador de C++.")

        client.close()
    except NameError:
        print(NameError)