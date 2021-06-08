const puppeteer = require('puppeteer');

(async() =>{
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto('https://datastudio.google.com/embed/reporting/2f2537fa-ac23-4f08-8741-794cdbedca03/page/ROITB', {
    waitUntil: 'networkidle0',
  });

  var teste;

  let DF = await page.evaluate(() => {
    const testando = [];

    for (let i = 0; i < 189; i++) {
      let sigla = document.querySelectorAll('.cell')[i].innerText;
      let ocupacao = document.querySelectorAll('.cell')[i += 4].innerText;
      let ultimatt = document.querySelectorAll('.cell')[i += 1].innerText;
      let fonte = document.querySelectorAll('.cell')[i += 1].innerText;

      testando.push({
        sigla,
        ocupacao,
        ultimatt,
        fonte
      });
    }

    return testando;
  });

  teste = DF;

  await page.goto('https://datastudio.google.com/embed/reporting/2f2537fa-ac23-4f08-8741-794cdbedca03/page/CPFTB%27,%7B', {
    waitUntil: 'networkidle0',
  });
  var resto_dados;

  let dados = await page.evaluate(() => {
    const testando = [];

    for (let i = 0; i <= 349; i++) {
      let sigla = document.querySelectorAll('.cell')[i].innerText
      let total_casos = document.querySelectorAll('.cell')[i+=1].innerText;
      let total_obitos = document.querySelectorAll('.cell')[i += 1].innerText;
      let recuperados = document.querySelectorAll('.cell')[i += 5].innerText;
      let pop_vac = document.querySelectorAll('.cell')[i += 4].innerText;
      i += 1;

      testando.push({
        sigla,
        total_casos,
        total_obitos,
        recuperados,
        pop_vac
      });
    }

    return testando;
  });
  resto_dados = dados;
  
  
  for(let i = 0; i<27;i++){
    for(let j =0 ; j<=26;j++){

      if(teste[i].sigla===resto_dados[j].sigla){
        
        teste[i].total_casos = resto_dados[j].total_casos;
        teste[i].total_obitos = resto_dados[j].total_obitos;
        teste[i].recuperados = resto_dados[j].recuperados;
        teste[i].pop_vac = resto_dados[j].pop_vac;
      }
    }

  }

  console.log(teste);

  await browser.close();
})
