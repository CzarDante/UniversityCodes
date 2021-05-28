// const express = require('express');
// const app = express();
const { fstat } = require('fs');
const puppeteer = require('puppeteer');

(async () => {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    await page.goto('https://coronavirusbra1.github.io/');
    // await page.screenshot({path: 'coronavirus.png'});

    let CovidUrl = 'https://coronavirusbra1.github.io/';

    await page.goto(CovidUrl, {waitUntil: 'networkidle2'});
    await page.evaluate(() => {
        let casos_geral = document.querySelector('div[class="valueLabel"]').innerText;
        print(casos_geral);
    });
    
    await browser.close();
})();
