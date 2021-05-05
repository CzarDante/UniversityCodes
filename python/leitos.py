import requests
import json

API_KEY="ttARBxNqq2oV"
PROJECT_TOKEN = "tNmBTD1qFpYz"
RUN_TOKEN ="t-xeQ_x1-tGk"

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

    def pega_ocupacao_estado(self,estado):
        data =  self.data['UF']
        for content in data:
            if content['name'].lower() == estado.lower():
                return 'Estado: ' + content['name'] + '\nTaxa de ocupação: ' + content['taxa_ocupacao'] + '\nUltima atualização: ' + content['ultima_att'] + '\nFonte: ' + content['fonte'] + '\n'
        return '0' 

dados = informacao(API_KEY,PROJECT_TOKEN)