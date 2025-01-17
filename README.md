# Simulador: Fábrica de sumo
![Gemini_Generated_Image_wiotblwiotblwiot](https://github.com/user-attachments/assets/0299f9b2-04ee-416b-8e23-8779c2ade0f6)

Uma fábrica de enchimento de sumos precisa de comprar novas máquinas para
a sua produção. Antes da compra, o concelho de administradores decidiu
mandar desenvolver uma simulação para aferir o nível da produção. A simulação
consiste no seguinte:

• A fábrica enche 2 tamanhos diferentes de pacotes de sumo. O de 200 ml
(PA) e o de 1 L (PB). Existem 2 filas para cada pacote, representando cada
uma das fases do processo. A primeira fila é do enchimento e a segunda
do embalamento. Cada fila está associada a uma máquina;


• Uma máquina de produção(enchimento, embalamento e empilhamento)
deverá ser representada por um TAD que possui o nome, tipo de
máquina, tempo de processamento, a quantidade de unidades
processadas num dia de produção, a fila de produtos a serem
processados e outros atributos que sejam necessários;


• Os pacotes são inseridos na fila inicial (uma fila para cada tipo de pacote);


• Os pacotes do tipo PA (200 ml) saem da fila e entram para a máquina de
enchimento. Depois do enchimento, os pacotes seguem em fila para a
máquina de embalamento num conjunto de 6. Enquanto não houver 6
pacotes na máquina, não é possível fazer o embalamento. Depois de sair
da máquina, já agrupados em 6 as embalagens são empilhadas. A
máquina empilha até 4 caixas de 6 cada;

• Os pacotes do tipo PB (1 L) seguem o mesmo processo do PA, com a
diferença de que serão embalados em grupos de 4 e empilhadas até 3
caixas;

• Cada pacote tem características próprias para que seja considerado em
condições para ser embalado. Caso um pacote esteja fora do padrão (tipo
ou peso errado) é descartado da fila e não entra na
