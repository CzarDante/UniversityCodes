const express = require('express');
const puppeteer = require('puppeteer');

const server = express();

server.get('/',async(request,response)=> {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto('https://datastudio.google.com/embed/reporting/2f2537fa-ac23-4f08-8741-794cdbedca03/page/ROITB',{
    waitUntil: 'networkidle0',
  });
  
  let DF = await page.evaluate(() => {
    let nome = document.querySelectorAll('.cell')[0].innerText
    let ocupacao = document.querySelectorAll('.cell')[4].innerText
    let ultimatt = document.querySelectorAll('.cell')[5].innerText
    let fonte = document.querySelectorAll('.cell')[6].innerText
    return{
      nome, 
      ocupacao, 
      ultimatt,
      fonte
    };
  });
  let RS = await page.evaluate(() => {
    let nome = document.querySelectorAll('.cell')[7].innerText
    let ocupacao = document.querySelectorAll('.cell')[11].innerText
    let ultimatt = document.querySelectorAll('.cell')[12].innerText
    let fonte = document.querySelectorAll('.cell')[13].innerText
    return{
      nome, 
      ocupacao, 
      ultimatt,
      fonte
    };
  });
  let SC = await page.evaluate(() => {
    let nome = document.querySelectorAll('.cell')[14].innerText
    let ocupacao = document.querySelectorAll('.cell')[18].innerText
    let ultimatt = document.querySelectorAll('.cell')[119].innerText
    let fonte = document.querySelectorAll('.cell')[20].innerText
    return{
      nome, 
      ocupacao, 
      ultimatt,
      fonte
    };
  });
  let MG = await page.evaluate(() => {
    let nome = document.querySelectorAll('.cell')[21].innerText
    let ocupacao = document.querySelectorAll('.cell')[25].innerText
    let ultimatt = document.querySelectorAll('.cell')[26].innerText
    let fonte = document.querySelectorAll('.cell')[27].innerText
    return{
      nome, 
      ocupacao, 
      ultimatt,
      fonte
    };
  });
  console.log({
    
    "estado_DF":DF.nome,
    "ocupacao_DF":DF.ocupacao,
    "ultima_att_DF":DF.ultimatt,
    "fonte_DF":DF.fonte,

    "estado_RS":RS.nome,
    "ocupacao_RS":RS.ocupacao,
    "ultima_att_RS":RS.ultimatt,
    "fonte_RS":RS.fonte,
  
    "estado_SC":SC.nome,
    "ocupacao_SC":SC.ocupacao,
    "ultima_att_SC":SC.ultimatt,
    "fonte_SC":SC.fonte,

    "estado_MG":MG.nome,
    "ocupacao_MG":MG.ocupacao,
    "ultima_att_MG":MG.ultimatt,
    "fonte_MG":MG.fonte,

    "estado_BA":BA.nome,
    "ocupacao_BA":BA.ocupacao,
    "ultima_att_BA":BA.ultimatt,
    "fonte_BA":BA.fonte,
  })
  response.send({
    "estado_DF":DF.nome,
    "ocupacao_DF":DF.ocupacao,
    "ultima_att_DF":DF.ultimatt,
    "fonte_DF":DF.fonte,

    "estado_RS":RS.nome,
    "ocupacao_RS":RS.ocupacao,
    "ultima_att_RS":RS.ultimatt,
    "fonte_RS":RS.fonte,

    "estado_SC":SC.nome,
    "ocupacao_SC":SC.ocupacao,
    "ultima_att_SC":SC.ultimatt,
    "fonte_SC":SC.fonte,

    "estado_MG":MG.nome,
    "ocupacao_MG":MG.ocupacao,
    "ultima_att_MG":MG.ultimatt,
    "fonte_MG":MG.fonte,

    "estado_BA":BA.nome,
    "ocupacao_BA":BA.ocupacao,
    "ultima_att_BA":BA.ultimatt,
    "fonte_BA":BA.fonte,
  });
  
  
  await browser.close();
});
const port = 3000
server.listen(port,() => {
  console.log(`server up acessa em http://localhost:${port}`)
})

