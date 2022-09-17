var precoNormal = {"1": "79.90",
                   "2": "21.90",
                   "3": "39.90",     
                   "4": "49.90",
                   "5": "59.90",
                   "6": "54.90",
                   "7": "49.90",
                   "8": "21.90",
                   "9": "29.90",
                   "10": "21.90",
                   "11": "69.90",
                   "12": "79.90",
                   "13": "39.90",
                   "14": "54.90",
                   "15": "29.90",
                   "16": "179.00",
                   "17": "39.90",
                   "18": "48.00",
                   "19": "77.90",
                   "20": "54.90"
                    };
var precoDesconto = {"1": "9.90",
                     "2": "14.00",
                     "3": "17.90",  
                     "4": "33.70",
                     "5": "32.90",
                     "6": "38.39",
                     "7": "23.49",
                     "8": "13.71",
                     "9": "12.89",
                     "10": "14.20",
                     "11": "39.88",
                     "13": "13.90",
                     "15": "15.75",
                     "19": "57.49",
                     "20": "29.97"
                    };

function fecharDetalhes()
{
    document.getElementsByTagName('section')[0].style.filter = 'none';
    const det = document.getElementById('expandido');
    det.style.display = 'none';
}

function abrirDetalhes(produto)
{
    document.getElementsByTagName('section')[0].style.filter = 'brightness(30%)';

    let pai = document.getElementsByName(produto);
    let filhos = pai[0].children;

    let source = filhos.item(0).getAttribute('src');
    let alternative = filhos.item(0).getAttribute('alt');
    let nomeProduto = filhos.item(1).textContent;
    let texto = filhos.item(2).textContent;
    
    let primario = document.getElementById('precoAtual');
    let secundario = document.getElementById('precoAnterior');
    
    let preco = precoDesconto[produto];
    let anterior = precoNormal[produto];
    if(preco == undefined){ // sem desconto
        primario.innerHTML = `Por ${anterior}`;
        primario.style.top = '-20%';
        secundario.innerHTML = 'nada'
        secundario.style.color = 'white';
    } else { // com desconto
        primario.innerHTML = `Por ${preco}`;
        primario.style.top = '0%';
        secundario.innerHTML = `De ${anterior}`;
        secundario.style.color = 'gray';
    }

    document.getElementById('imagemModal').src = source;
    document.getElementById('imagemModal').alt = alternative;
    document.getElementById('produto').innerHTML = nomeProduto;
    document.getElementById('descricao').innerHTML = texto;

    const det = document.getElementById('expandido');
    det.style.display = 'block';
}