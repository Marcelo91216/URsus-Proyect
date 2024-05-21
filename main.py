# main.py
import vt
from dotenv import load_dotenv
import os
import sys
import modelSUS as model

load_dotenv()

url = input("Introduzca un URL: ")
if len(url) < 2:
    print("Por favor introduzca un valor")
elif "APIKEY" in os.environ:
    try:
        is_valid = model.is_valid_url(url)
        client = vt.Client(str(os.getenv("APIKEY")))

        info = client.get_object("/urls/{}".format(vt.url_id(url)))
        print(info.last_analysis_stats)

        analysis = client.scan_url(url)
        print(analysis)

        print(
            f"La URL es {'válida' if is_valid else 'inválida'} según el validador de C++."
        )

        client.close()
    except NameError:
        print(NameError)