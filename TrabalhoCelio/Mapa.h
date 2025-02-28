#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>

class Mapa {
public:

	ALLEGRO_BITMAP* __chao = NULL;

	const int __largura__tela = 1280;
	const int __altura__tela = 768;

	const int __fpsGame = 60;

	int __representacaoMapa[25][50] = {
		1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 10, 11, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 21, 20, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 12, 13, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 23, 22, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 10, 11, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 25, 24, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 12, 13, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 27, 26, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 14, 15, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 21, 20, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 16, 17, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 23, 22, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 10, 11, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 21, 20, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 12, 13, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 23, 22, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 10, 11, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 12, 13, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 14, 15, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 25, 24, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 16, 17, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 27, 26, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 14, 15, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 21, 20, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 16, 17, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 23, 22, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 10, 11, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 25, 24, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 12, 13, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 27, 26, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 14, 15, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 25, 24, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 16, 17, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 27, 26, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 10, 11, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 28, 25, 24, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 12, 13, 19, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 29, 27, 26, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	Mapa() {};

	void carregarImagemChao(const char* caminhoImagem);
	void construirMapa(int mapa[25][50]);
};

void Mapa::carregarImagemChao(const char* caminhoImagem) {
	__chao = al_load_bitmap(caminhoImagem);
}

void Mapa::construirMapa(int mapa[25][50]) {
	for (int x = 0; x < 50; x++) {
		for (int y = 0; y < 25; y++) {

			//chao
			if (mapa[y][x] == 1) {
				al_draw_bitmap_region(this->__chao, 0, 0, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 2) {
				al_draw_bitmap_region(this->__chao, 32, 0, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 3) {
				al_draw_bitmap_region(this->__chao, 32, 32, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 4) {
				al_draw_bitmap_region(this->__chao, 64, 0, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 5) {
				al_draw_bitmap_region(this->__chao, 64, 32, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 6) {
				al_draw_bitmap_region(this->__chao, 0, 32, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 7) {
				al_draw_bitmap_region(this->__chao, 0, 64, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 8) {
				al_draw_bitmap_region(this->__chao, 64, 64, 32, 32, x * 32, y * 32, 0);
			}

			// 
			if (mapa[y][x] == 10) {
				al_draw_bitmap_region(this->__chao, 0, 96, 32, 32, x * 32, y * 32, 0);
		
			}
			if (mapa[y][x] == 11) {
				al_draw_bitmap_region(this->__chao, 32, 96, 32, 32, x * 32, y * 32, 0);
				
			}
			if (mapa[y][x] == 12) {
				al_draw_bitmap_region(this->__chao, 0, 128, 32, 32, x * 32, y * 32, 0);
				
			}
			if (mapa[y][x] == 13) {
				al_draw_bitmap_region(this->__chao, 32, 128, 32, 32, x * 32, y * 32, 0);
				
			}

			// 
			if (mapa[y][x] == 14) {
				al_draw_bitmap_region(this->__chao, 64, 96, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 15) {
				al_draw_bitmap_region(this->__chao, 96, 96, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 16) {
				al_draw_bitmap_region(this->__chao, 64, 128, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 17) {
				al_draw_bitmap_region(this->__chao, 96, 128, 32, 32, x * 32, y * 32, 0);
			}

			if (mapa[y][x] == 18) {
				al_draw_bitmap_region(this->__chao, 128, 96, 32, 32, x * 32, y * 32, 0);
			}
			if (mapa[y][x] == 19) {
				al_draw_bitmap_region(this->__chao, 128, 128, 32, 32, x * 32, y * 32, 0);
			}

			if (mapa[y][x] == 20) {
				al_draw_bitmap_region(this->__chao, 0, 96, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);

			}
			if (mapa[y][x] == 21) {
				al_draw_bitmap_region(this->__chao, 32, 96, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);

			}
			if (mapa[y][x] == 22) {
				al_draw_bitmap_region(this->__chao, 0, 128, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);

			}
			if (mapa[y][x] == 23) {
				al_draw_bitmap_region(this->__chao, 32, 128, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);

			}

			// 
			if (mapa[y][x] == 24) {
				al_draw_bitmap_region(this->__chao, 64, 96, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);
			}
			if (mapa[y][x] == 25) {
				al_draw_bitmap_region(this->__chao, 96, 96, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);
			}
			if (mapa[y][x] == 26) {
				al_draw_bitmap_region(this->__chao, 64, 128, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);
			}
			if (mapa[y][x] == 27) {
				al_draw_bitmap_region(this->__chao, 96, 128, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);
			}

			if (mapa[y][x] == 28) {
				al_draw_bitmap_region(this->__chao, 128, 96, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);
			}
			if (mapa[y][x] == 29) {
				al_draw_bitmap_region(this->__chao, 128, 128, 32, 32, x * 32, y * 32, ALLEGRO_FLIP_HORIZONTAL);
			}
		}
	}
}

