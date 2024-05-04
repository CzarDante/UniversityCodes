from cProfile import label
import time
from turtle import color
import pandas as pd
from glob import glob
import seaborn as sns

import matplotlib as mpl
from matplotlib.animation import FuncAnimation
import matplotlib.pyplot as plt
import numpy as np 
import matplotlib.gridspec as gridspec

import json
while True:
  data = sorted(glob('./python/2turno/*.json'))

  allresults = pd.concat((pd.read_json(cont) for cont in data))

  candidatos = allresults["cand"]
  total_votes = sum(int(v["vap"]) for v in candidatos)

  bolso = []
  nuna = []
  horas = []

  for candidato in candidatos:
    name = candidato["nm"]
    total= candidato["vap"]
    percentage = candidato["pvap"]
    qtd_votos = candidato["vap"]
    if(name == 'JAIR BOLSONARO'):
      tempF = int(qtd_votos)
      bolso.append(tempF)
    if(name == 'LULA'):
      tempF2 = int(qtd_votos)
      nuna.append(tempF2)

  tam = len(data)
  for i in range(tam):
    test = data.pop(0)
    tempe = json.load(open(f'{test}', 'r'))
    hora = tempe["hg"]
    horas.append(hora)
    percent = tempe["pst"]
  
  # plt.cla()

  # plt.plot(horas, bolso, color="green", label='Bolsonaro')
  # # plt.plot(horas, bolso, 'o', color="green")

  # plt.plot(horas, nuna, color="red",label='Lula')
  # # plt.plot(horas, nuna, 'o',color="red")

  # plt.ylabel("Qtd Votos")
  # plt.xlabel("Hora")

  # plt.title(f"{percent} % apurado")

  # plt.legend(('Bolsonaro','','Lula',''), loc='upper left', shadow=True)

  # plt.tight_layout()

  x = ['58,09','55,04','52,01','49,53']
  y = ['10:58','11:20','11:40','12:00']
  plt.plot(y,x)
  plt.show()
  time.sleep(4)