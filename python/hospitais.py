import requests
import json

API_KEY="ttARBxNqq2oV"
PROJECT_TOKEN = "tOVhWrCLDZCO"
RUN_TOKEN ="tPj1mPiTSW-N"

class informacao:
    def __init__(self,api_key,PROJECT_TOKEN):
        self.api_key = api_key
        self.PROJECT_TOKEN = PROJECT_TOKEN
        self.params = {
            "api_key":self.api_key
        }
        self.info_att()
    def info_att(self):
        response = requests.get(f'https://www.parsehub.com/api/v2/projects/{PROJECT_TOKEN}/last_ready_run/data', params={"api_key":API_KEY})
        self.data =  json.loads(response.text)

    def pega_ocupacao_hospitais(self,hospital):
        data =  self.data['hospitais']
        for content in data:
            if content['name'].lower == hospital.lower():
                return content['name']
        return '0' 

dados = informacao(API_KEY,PROJECT_TOKEN)
print(dados.pega_ocupacao_hospitais('hbdf'))


