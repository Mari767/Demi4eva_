#include "Declaration.h"
#include "Functions.h"
#include <sstream> // для вывода строк  здоровья,...

int main(bool is_menu)
{
	// Изначальные значения и их установление
	int LvL = 3;
	int Health = 10;
	int Score_by_destroying_bricks = 0;

	//char Map_Current_Level[Height_Map][Width_Map];
	char** Map_Current_Level = new char* [Height_Map];
	/* выделение памяти для каждой строки и заполнение массива указателей */
	for (int i = 0; i < Height_Map; i++) {
		Map_Current_Level[i] = new char[Width_Map];
	}

	// Загрузка карты и заполнение структуры блоков
	LvL_Up(Map_Current_Level, 3);
	List_Bricks* head = NULL;
	head = Creation_List_Bricks(Map_Current_Level);

	// Declaration bool
	bool  I_should_close_the_program = false;
	bool LvL_is_up = false;
	bool all_bricks_destroyed = false;
	bool is_Space_Pressed_for_moving_ball = false;
	bool are_ball_and_racket_moving_together = true;
	bool should_i_close_window = false;
	bool player_lose = false;

	// Declaration int
	int check_ball_is_down;
	int colvo_not_destroyed_bricks;

	// Declaration window
	RenderWindow window(VideoMode(Window_Width, Window_Height), "My Game Works!");

	// My ball
	CircleShape ball;
	ball.setFillColor(Color(182, 170, 223));
	ball.setRadius(Ball_Radius);
	ball.setOrigin(Ball_Radius, Ball_Radius);
	ball.setPosition(Playing_Field_Width / 2, Window_Height - 90);
	Figure ball_direction{ 0, 0, 0, 0, 0, 0 };

	// My racket
	RectangleShape racket;
	racket.setPosition(Playing_Field_Width / 2, Window_Height - 85);
	racket.setFillColor(Color(115, 119, 205));
	racket.setSize({ Racket_Width, Racket_Height });
	racket.setOrigin(Racket_Width / 2.f, Racket_Height / 2.f);
	Figure racket_direction{ 0, 0, 0, 0, 0, 0 };

	// My bricks
	Texture image;
	image.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\Images\\bricks.jpg");
	Sprite brick;
	brick.setTexture(image);

	Font font;//шрифт 
	font.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\ITCKRIST.ttf");
	Text text("", font, 18);
	text.setFillColor(Color(200, 191, 231));
	text.setStyle(Text::Bold);

	// настройка text lose or win
	Text text_action("", font, 60);
	text_action.setFillColor(Color(200, 191, 231));
	text_action.setStyle(Text::Bold);
	text_action.setPosition(Window_Width / 2 - 120, Window_Height / 2 - 40);

	Text text_return_to_menu("To get to the menu press the key Escape.", font, 26);
	text_return_to_menu.setFillColor(Color(100, 67, 86));
	//text_return_to_menu.setStyle(Text::Bold);
	text_return_to_menu.setPosition(145, Window_Height - 55);

	// Частота кадров
	window.setFramerateLimit(70);

	// Работа с окном
	while (window.isOpen())
	{
		if (is_menu) { Menu(window); is_menu = false; }

		// Закрытие окна
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) { window.close(); break; }
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) { window.close(); break; }
		}

		//переход на другой уровень или  reatart/выход  после последнего уровня
		if (All_Bricks_Destroyed(Map_Current_Level, &LvL_is_up))
		{
			are_ball_and_racket_moving_together = true;
			is_Space_Pressed_for_moving_ball = false;
			if (LvL_is_up == true) {
				LvL++;
				Health = 3;
				Rree_List_Bricks(head);

				if (LvL == 4) { is_menu = true; }
				else { LvL_Up(Map_Current_Level, LvL); head = Creation_List_Bricks(Map_Current_Level); }

			}
		}

		// Нажатие Space Разрешение шару двигаться = начало движения шара
		if (is_Space_Pressed_for_moving_ball) {
			ball_direction.x = -Ball_Speed;
			ball_direction.y = -Ball_Speed;
			is_Space_Pressed_for_moving_ball = false; //заглушаю, чтоб не ломался цикл
		}
		// Шар двигается за ракеткой   (начало уровня, шар выпал за поле)
		if (are_ball_and_racket_moving_together)
		{
			ball.setPosition(racket.getPosition().x, racket.getPosition().y - 30);

			//// Нажатие клавиши Space = разрешение шару двигаться
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				are_ball_and_racket_moving_together = false;
				is_Space_Pressed_for_moving_ball = true;
			}
		}

		// Движение мяча
		ball.move(ball_direction.x, ball_direction.y);
		// Мяч отбивается от стен //  проверка выпадания шара за пределы поля (вниз)
		check_ball_is_down = Update_Ball(ball, ball_direction);

		// Если шар выпал, теряем жизнь
		// Если потеряны все жизнь, то выбор игрока начать сначала или закончить игру
		if (check_ball_is_down == 0)
		{
			are_ball_and_racket_moving_together = true;
			Health--;
		}

		// Ракетка не уходит за пределы поля ( лево/право )
		Update_Racket(racket, racket_direction);
		// Движение ракетки
		racket.move(racket_direction.x, racket_direction.y);

		// Шар отбивается от ракетки
		Intersection(ball_direction, racket_direction);

		// Шар отбивается и уничтожает блоки
		// Блоки меняют цвет
		// Счет очков
		Intersection_Ball_With_Bricks(ball, ball_direction, Map_Current_Level, &Score_by_destroying_bricks, head);

		window.clear(Color::Black);

		//Рисуем карту
		for (int i = 0; i < Height_Map; i++) {
			for (int j = 0; j < Width_Map - 1; j++) {

				if (*(*(Map_Current_Level + i) + j) != ' ') {

					if (*(*(Map_Current_Level + i) + j) == 'w') { brick.WHITE; }
					if (*(*(Map_Current_Level + i) + j) == 'p') { brick.PINK; }
					if (*(*(Map_Current_Level + i) + j) == 'u') { brick.PURPUR; }
					if (*(*(Map_Current_Level + i) + j) == 'g') { brick.GREEN; }
					if (*(*(Map_Current_Level + i) + j) == 's') { brick.SALAT; }
					if (*(*(Map_Current_Level + i) + j) == 'y') { brick.GREY; }

					brick.setPosition(j * Brick_Width, i * Brick_Height);
				}
				window.draw(brick);//рисуем квадратики на экран
			}
		}

		if (Health == 0 || LvL == 4) {
			racket.setPosition(Playing_Field_Width / 2, Window_Height - 85);
			ball.setPosition(racket.getPosition().x, racket.getPosition().y - 30);
		}
		// рисуем шар и ракетку
		window.draw(ball);
		window.draw(racket);

		if (Health == 0) {
			player_lose = true;
			text_action.setString("You losed(((");
			while (true) {
				window.draw(text_action);
				window.draw(text_return_to_menu);
				window.display();
				if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) { break; }
			}
			break;
		}
		if (LvL == 4) {
			text_action.setString("You won!");
			while (true) {
				window.draw(text_action);
				window.draw(text_return_to_menu);
				window.display();
				if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) { break; }
			}
			break;
		}

		// Ввод текущих показателей на экран в виде текста
		ostringstream Score_by_destroying_bricks__string, health_string, LvL_string;
		// Надпись Score
		Score_by_destroying_bricks__string << Score_by_destroying_bricks;     //занесли в нее число очков, то есть формируем строку
		text.setString("Score: " + Score_by_destroying_bricks__string.str());  //задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(Window_Width - 120, Window_Height - 40);                //задаем позицию текста, отступая от центра камеры
		window.draw(text);
		// Надпись здоровье
		health_string << Health;
		text.setString("Health: " + health_string.str());
		text.setPosition(35, Window_Height - 40);
		window.draw(text);
		// Надпись уровень
		LvL_string << LvL;
		text.setString("Level:  " + LvL_string.str());
		text.setPosition(Window_Width - 120, Window_Height - 63);
		window.draw(text);

		window.display();
	}
	Rree_List_Bricks(head);

	if (player_lose == true)
		if (Menu(window, player_lose) == true) { return main(false); }

	// удаление двумерного динамического массива char (карта)
	for (int i = 0; i < Height_Map; i++) {
		delete[] Map_Current_Level[i];
	}
	delete[] Map_Current_Level;

	return 0;
}
