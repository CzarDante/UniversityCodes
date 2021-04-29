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
print(dados.pega_ocupacao_estado('ac'))
print(dados.pega_ocupacao_estado('al'))
print(dados.pega_ocupacao_estado('ap'))
print(dados.pega_ocupacao_estado('am'))
print(dados.pega_ocupacao_estado('ba'))
print(dados.pega_ocupacao_estado('ce'))
print(dados.pega_ocupacao_estado('df'))
print(dados.pega_ocupacao_estado('es'))
print(dados.pega_ocupacao_estado('go'))
print(dados.pega_ocupacao_estado('ma'))
print(dados.pega_ocupacao_estado('mt'))
print(dados.pega_ocupacao_estado('ms'))
print(dados.pega_ocupacao_estado('mg'))
print(dados.pega_ocupacao_estado('pa'))
print(dados.pega_ocupacao_estado('pb'))
print(dados.pega_ocupacao_estado('pr'))
print(dados.pega_ocupacao_estado('pe'))
print(dados.pega_ocupacao_estado('pi'))
print(dados.pega_ocupacao_estado('rj'))
print(dados.pega_ocupacao_estado('rn'))
print(dados.pega_ocupacao_estado('rs'))
print(dados.pega_ocupacao_estado('ro'))
print(dados.pega_ocupacao_estado('rr'))
print(dados.pega_ocupacao_estado('sc'))
print(dados.pega_ocupacao_estado('sp'))
print(dados.pega_ocupacao_estado('se'))
print(dados.pega_ocupacao_estado('to'))