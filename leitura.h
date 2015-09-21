# Leitura-ppm

#include <fstream>
#include <math.h>
#include "Image.h"

Image* leitura {
public:
	int width, height;
	ifstream arq;
	char linha[1024];
	arq.open("c:\\imagem1.ppm");
	arq >> linha; // tipo de arquivo
	arq >> linha; //Comentario Pode ter ou não 
	if (linha == "#") {
		arq.getline(linha, 1024);
	}
	else
	{
		width = atoi(linha);
	}
	arq >> linha;
	height = atoi(linha);
	arq >> linha;
	image = new Image(width, height);

	Image *image = new Image(width, height);
	for (int i = 0; i < width * height; i++) {
		int a, r, g, b;
		arq >> a >> r >> g >> b;
		int x = i % width;
		int y = i / width;
		y = height - y - 1; // inverte o y
		int pixel = (a << 24) | (r << 16) | (g << 8) | b;
		image->setPixels(pixel, x, y);
	}
	return image;
};
