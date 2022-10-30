import requests
import json
import time
import os
url = 'https://resultados.tse.jus.br/oficial/ele2022/545/dados-simplificados/br/br-c0001-e000545-r.json'

while True:
    now = time.time()
    resp = requests.get(url=url)
    data = resp.json()
    os.system('cls') or None
    json_object = json.dumps(data,indent=4)
    with open(f"D:/CCO/UniversityCodes/python/2turno/{now}.json", "w") as outfile:
        outfile.write(json_object)
    try:
        candidatos = data["cand"]
        total_votes = sum(int(v["vap"]) for v in candidatos)
        total_votes_percent = data["pst"]
        hora = data["hg"]
        print(now, "==" * 10)
        print(f"\nTotal de votos: {total_votes} ({total_votes_percent}%) {hora}\n")
        for candidato in candidatos:
            name = candidato["nm"]
            total= candidato["vap"]
            percentage = candidato["pvap"]
            print(f"{name}: {total} ({percentage}%)")        
        time.sleep(120)
    except:
        print("Erro")
        time.sleep(5)