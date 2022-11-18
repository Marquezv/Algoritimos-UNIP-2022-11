# COLOCAR O SCRIPT EM UM PASTA SEPARADA (GERA 5 ARQUIVOS)
import random, os

def randomList():

	valorMin, valorMax, tamanho= 1,150, 100
	
	res = random.sample(range(valorMin, valorMax), tamanho)
	ordenada, concava, convexa, crescente, decresente = listSet(res)

	# Todas
	# for i in listSet(res):
	# 	print(i)

	# Alterar a opção
	
	writerList(ordenada, "ordenada",)
	writerList(concava, "concava", )
	writerList(convexa, "convexa")
	writerList(crescente, "crescente")
	writerList(decresente, "decresente")

def writerList(lista, nome):
	fileStr = f"numeros{len(lista)}_{nome}.txt"

	if searchFiles(fileStr):
		arquivo = open(fileStr, "w")
		for i in lista:
			arquivo.write(str(i)+"\n")
	else:
		arquivo = open(fileStr, "x")
		for i in lista:
			arquivo.write(str(i)+"\n")

def searchFiles(file):
	arquivos = os.listdir(os.getcwd() )
	for i in arquivos:
		return True if i == file else False

def quickSort(lista):
	if len(lista) < 2:
		return lista
	else:
		pivo = lista[0]
		menores = [i for i in lista[1:] if i <= pivo]
		maiores = [i for i in lista[1:] if i > pivo]
		return quickSort(menores) + [pivo] + quickSort(maiores)

def listSet(res):
	
	ordenada = list(quickSort(res))
	concava = list(map(lambda x: - x ** 2 + 10 * x - 14, ordenada))
	convexa = list(map(lambda x: - x ** 2 + 10 * x + 14, ordenada))
	crescente = list(sorted(ordenada))
	decresente = list(sorted(ordenada, reverse=True))
	return ordenada, concava, convexa, crescente, decresente
randomList()


# COLOCAR O SCRIPT EM UM PASTA SEPARADA (GERA 5 ARQUIVOS)
