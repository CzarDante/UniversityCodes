% Ler a imagem original
imagem_original = imread('h2rgray.jpg');

% Obter as dimensões da imagem original
[linhas, colunas] = size(imagem_original);

% Definir fator de aumento (2 neste caso)
fator_aumento = 5;

% Calcular as novas dimensões
nova_altura = linhas * fator_aumento;
nova_largura = colunas * fator_aumento;

% Inicializar a nova imagem com zeros
nova_imagem = zeros(nova_altura, nova_largura);

% Loop for para copiar os pixels da imagem original para a nova imagem
for i = 1:linhas
    for j = 1:colunas
        pixel = imagem_original(i, j);
        nova_imagem((i-1)*fator_aumento+1:i*fator_aumento, (j-1)*fator_aumento+1:j*fator_aumento) = pixel;
    end
end

% Exibir a imagem original e a imagem aumentada

imshow(imagem_original);
title('Imagem Original');

figure(2);
imshow(uint8(nova_imagem)); % Converter de double para uint8 para exibição
title('Imagem Aumentada');
