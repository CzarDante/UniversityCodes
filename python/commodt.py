import requests
import time
import matplotlib.pyplot as plt
import schedule
from bs4 import BeautifulSoup

def get_data_and_plot():

    commodity_prices = {}
    
    plt.figure(figsize=(10,6))
    plt.title('Commodity Prices')
    plt.xlabel('Time')
    plt.ylabel('Price (USD)')
    plt.grid(True)
    colors = ['b', 'g', 'r', 'c', 'm']
    commodities = ['BRENTOIL', 'ETHANOL', 'SUGAR', 'WTIOIL']

    while True:
        response = requests.get('https://commodities-api.com/api/latest?access_key=7t1scx52rh0u096bo2pwjhy5g229t38k8zib7mxu4gvtk0f062gjse51sgdn&base=USD&symbols=SUGAR,BRENTOIL,WTIOIL,ETHANOL')
        data = response.json()
        rates = data['data']['rates']
        for i, commodity in enumerate(commodities):
            prices = []
            if commodity in rates:
                prices.append(1/rates[commodity])
            else:
                print(f"Commodity {commodity} not found")
                continue
            if commodity not in commodity_prices:
                commodity_prices[commodity] = prices
            else:
                commodity_prices[commodity].append(prices[0])
        
        plt.clf()
        for i, commodity in enumerate(commodities):
            plt.plot(commodity_prices[commodity], '-o', label=commodity, color=colors[i])
            for j, price in enumerate(commodity_prices[commodity]):
                plt.text(j, price, f'{price:.2f}')
        plt.legend()
        plt.pause(86400) # pausa por 24 horas

get_data_and_plot()