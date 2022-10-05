import requests
import json
import time
import os
url = 'https://resultados.tse.jus.br/oficial/ele2022/546/dados-simplificados/df/df-c0003-e000546-r.json'

while True:
    now = time.time()
    resp = requests.get(url=url)
    data = resp.json()
    os.system('cls') or None
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
        time.sleep(30)
    except:
        print("Erro")
        time.sleep(5)