#include "Declaration.h"
#include "Functions.h"

void LvL_Up(char** Map_Current_Level, int LvL) {
	char symbol;
	FILE* file = NULL;
	// ¬ыбор уровн€!!!
	char* file_name_Map_I = new char[20]{ "Map_I.txt" };
	char* file_name_Map_II = new char[20]{ "Map_II.txt" };
	char* file_name_Map_III = new char[20]{ "Map_III.txt" };

	if (LvL == 1) { file = fopen(file_name_Map_I, "rt"); }
	if (LvL == 2) { file = fopen(file_name_Map_II, "rt"); }
	if (LvL == 3) { file = fopen(file_name_Map_III, "rt"); }

	if (file == NULL) { exit(0); }

	// —читка карты в программу !!!
	**Map_Current_Level = '\0';
	for (int i = 0; i < Height_Map; i++) {
		for (int j = 0; j < Width_Map; j++) {
			fscanf(file, "%c", &symbol);
			*(*(Map_Current_Level + i) + j) = symbol;
		}
	}
	delete[] file_name_Map_I;
	delete[] file_name_Map_II;
	delete[] file_name_Map_III;
}

int  Update_Ball(CircleShape& ball, Figure& direction) {

	direction.left = ball.getPosition().x - Ball_Radius;
	direction.right = ball.getPosition().x + Ball_Radius;
	direction.top = ball.getPosition().y - Ball_Radius;
	direction.bottom = ball.getPosition().y + Ball_Radius;

	if (direction.left <= 0) { direction.x = Ball_Speed; }
	if (direction.right >= Playing_Field_Width) { direction.x = -Ball_Speed; }
	if (direction.top <= 0) { direction.y = Ball_Speed; }
	if (direction.bottom >= Window_Height) { return 0; }
}

void Update_Racket(RectangleShape& racket, Figure& direction) {

	direction.left = racket.getPosition().x - Racket_Width / 2.f;
	direction.right = racket.getPosition().x + Racket_Width / 2.f;
	direction.top = racket.getPosition().y - Racket_Height / 2.f;
	direction.bottom = racket.getPosition().y + Racket_Height / 2.f;

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && direction.left > 6) { direction.x = -Racket_Speed; }
	else if (Keyboard::isKeyPressed(Keyboard::Right) && direction.right < Playing_Field_Width - 6) { direction.x = Racket_Speed; }
	else { direction.x = 0; }
}

// ball and racket
bool Is_Intersection(Figure& ball, Figure& racket)
{
	return ball.right >= racket.left && ball.left <= racket.right &&
		ball.bottom >= racket.top && ball.top <= racket.bottom;
}
// ball and racket
void Intersection(Figure& ball, Figure& racket)
{
	if (!Is_Intersection(ball, racket))  return;
	ball.y = -Ball_Speed;
}

void Ball_changes_directions_after_hitting_blocks(Figure& ball, Figure& brick)
{
	if (!Is_Intersection(ball, brick)) return;

	// —читаем все пересечени€ (шар залазит на блоки)
	float cross_left = ball.right - brick.left;
	float cross_right = brick.right - ball.left;
	float cross_top = ball.bottom - brick.top;
	float cross_bottom = brick.bottom - ball.top;

	// м€чик пришел с той стороны, где меньше перекрытие
	bool ballFromLeft(abs(cross_left) < abs(cross_right));
	bool ballFromTop(abs(cross_top) < abs(cross_bottom));

	// считаем перекрыти€ по ос€м
	float min_cross_X = ballFromLeft ? cross_left : cross_right;
	float min_cross_Y = ballFromTop ? cross_top : cross_bottom;

	if (abs(min_cross_X) < abs(min_cross_Y)) { ball.x = ballFromLeft ? -Ball_Speed : Ball_Speed; }
	else { ball.y = ballFromTop ? -Ball_Speed : Ball_Speed; }
}

void Intersection_Ball_With_Bricks(CircleShape& ball, Figure& dir_ball, char** Map_Current_Level, int* Score_by_destroying_bricks, List_Bricks* head) {

	List_Bricks* temp = head;

	int list_x = ball.getPosition().x / Brick_Width;
	int list_y = ball.getPosition().y / Brick_Height;
	float ball_x = ball.getPosition().x;
	float ball_y = ball.getPosition().y;

	int temp_number_element_for_list = list_y * (Width_Map - 1) + list_x;
	int i = 0;
	while (i != temp_number_element_for_list)
	{
		temp = temp->next;
		i++;
	}

	if (temp->color != ' ') {

		// For Window and Map    if without LIST!!! 
		/*if (Map_Current_Level[y][x] != ' ' ) {
		if (Map_Current_Level[y][x] == 'w') { Map_Current_Level[y][x] = ' '; (*Score_by_destroying_bricks)++; }
		else if (Map_Current_Level[y][x] == 'p') { Map_Current_Level[y][x] = 'y'; }
		else if (Map_Current_Level[y][x] == 'u') { Map_Current_Level[y][x] = 'p'; }
		else if (Map_Current_Level[y][x] == 'g') { Map_Current_Level[y][x] = 's'; }
		else if (Map_Current_Level[y][x] == 's') { Map_Current_Level[y][x] = 'y'; }
		else if (Map_Current_Level[y][x] == 'y') { Map_Current_Level[y][x] = ' '; }*/

	/*	if (Map_Current_Level[list_y][list_x] != ' ' ) {
		if (Map_Current_Level[list_y][list_x] == 'w') { Map_Current_Level[list_y][list_x] = ' '; (*Score_by_destroying_bricks)++; }
		else if (Map_Current_Level[list_y][list_x] == 'p') { Map_Current_Level[list_y][list_x] = ' '; }
		else if (Map_Current_Level[list_y][list_x] == 'u') { Map_Current_Level[list_y][list_x] = ' '; }
		else if (Map_Current_Level[list_y][list_x] == 'g') { Map_Current_Level[list_y][list_x] = ' '; }
		else if (Map_Current_Level[list_y][list_x] == 's') { Map_Current_Level[list_y][list_x] = ' '; }
		else if (Map_Current_Level[list_y][list_x] == 'y') { Map_Current_Level[list_y][list_x] = ' '; }*/


		//For List and Destroying bricks
		(temp->colvo_touch)++;
		++(*Score_by_destroying_bricks);

		/*temp->color = ' ';
			*(*(Map_Current_Level + list_y) + list_x) = ' ';*/


		if (temp->colvo_touch == temp->score) {
			*(*(Map_Current_Level + list_y) + list_x) = ' ';  temp->color = ' '; temp->color = ' ';
		}
		// Color change depending on color
		if (temp->color == 'p')
		{
			*(*(Map_Current_Level + list_y) + list_x) = 'y';
			temp->color = 'y';
		}
		else if (temp->color == 'u')
		{
			*(*(Map_Current_Level + list_y) + list_x) = 'p';
			temp->color = 'p';
		}
		else if (temp->color == 'g')
		{
			*(*(Map_Current_Level + list_y) + list_x) = 's';
			temp->color = 's';
		}
		else if (temp->color == 's')
		{
			*(*(Map_Current_Level + list_y) + list_x) = 'y';
			temp->color = 'y';
		}
		// Look at bricks position
		Figure brick;
		brick.left = list_x * Brick_Width;
		brick.right = list_x * Brick_Width + Brick_Width;
		brick.top = list_y * Brick_Height;
		brick.bottom = list_y * Brick_Height + Brick_Height;

		Ball_changes_directions_after_hitting_blocks(dir_ball, brick);
	}
}


bool All_Bricks_Destroyed(char** Map_Current_Level, bool* LvL_is_up) {

	int colvo_not_destroyed_bricks = 0;
	for (int i = 0; i < Height_Map; i++) {
		for (int j = 0; j < Width_Map - 1; j++) {
			if (*(*(Map_Current_Level + i) + j) != ' ') {
				colvo_not_destroyed_bricks++;
			}
		}
	}
	if (colvo_not_destroyed_bricks == 0) { *LvL_is_up = true;  return  true; }
	else return false;
}

List_Bricks* Creation_List_Bricks(char** Map_Current_Level) {

	List_Bricks* head = NULL;
	List_Bricks* tail = NULL;
	List_Bricks* temp = NULL;
	int number = 0;
	for (int i = 0; i < Height_Map; i++) {
		for (int j = 0; j < Width_Map - 1; j++) {

			temp = (struct List_Bricks*)malloc(sizeof(struct List_Bricks));
			if (head == NULL) {
				head = tail = temp;
			}
			else {
				tail->next = temp;
				tail = temp;
			}
			temp->color = *(*(Map_Current_Level + i) + j);
			temp->colvo_touch = 0;
			temp->number = number++;
			if (*(*(Map_Current_Level + i) + j) == 'w') { temp->score = 1; }
			if (*(*(Map_Current_Level + i) + j) == 'p') { temp->score = 2; }
			if (*(*(Map_Current_Level + i) + j) == 'u') { temp->score = 3; }
			if (*(*(Map_Current_Level + i) + j) == 'g') { temp->score = 3; }
			if (*(*(Map_Current_Level + i) + j) == 's') { temp->score = 2; }
			if (*(*(Map_Current_Level + i) + j) == 'y') { temp->score = 1; }
		}
	}
	temp->next = NULL;
	return head;
}

void Rree_List_Bricks(List_Bricks*& head) {

	List_Bricks* temp = head;
	while (temp)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}


bool  Menu(RenderWindow& window, bool player_lose) {

	Image  image_Start, image_Rules, image_Exit, image_try_again;
	Texture texture_Background, texture_button_Start, texture_button_Rules, texture_button_Exit, texture_window_rules, texture_button_try_again;

	texture_Background.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\Images\\background.png");
	texture_window_rules.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\Images\\window_rules.png");

	image_Start.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\Images\\start.png");
	image_Start.createMaskFromColor(Color(255, 255, 255));
	texture_button_Start.loadFromImage(image_Start);

	image_Exit.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\Images\\exit.png");
	image_Exit.createMaskFromColor(Color(255, 255, 255));
	texture_button_Exit.loadFromImage(image_Exit);

	image_Rules.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\Images\\rules.png");
	image_Rules.createMaskFromColor(Color(255, 255, 255));
	texture_button_Rules.loadFromImage(image_Rules);

	image_try_again.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\Images\\try again.png");
	image_try_again.createMaskFromColor(Color(255, 255, 255));
	texture_button_try_again.loadFromImage(image_try_again);



	Sprite Background_window_menu, Window_Rules, Button_Start, Button_Rules, Button_Exit, Button_try_again;

	Background_window_menu.setTexture(texture_Background), Window_Rules.setTexture(texture_window_rules), Button_try_again.setTexture(texture_button_try_again),
		Button_Start.setTexture(texture_button_Start), Button_Exit.setTexture(texture_button_Exit), Button_Rules.setTexture(texture_button_Rules);

	Background_window_menu.setTextureRect(IntRect(0, 0, Window_Width, Window_Height));
	Window_Rules.setTextureRect(IntRect(0, 0, Window_Width, Window_Height));

	Button_Start.setTextureRect(IntRect(0, 0, 250, 100));
	Button_Rules.setTextureRect(IntRect(0, 0, 250, 100));
	Button_Exit.setTextureRect(IntRect(0, 0, 250, 100));
	Button_try_again.setTextureRect(IntRect(0, 0, 250, 100));

	Button_Start.setPosition(280, 80);
	Button_Rules.setPosition(280, 210);
	Button_Exit.setPosition(280, 340);
	Button_try_again.setPosition(280, 180);

	Font font;
	font.loadFromFile("C:\\Users\\mdemi\\source\\repos\\Mari767\\Demi4eva_\\Term_2\\Course work\\Arcanoid\\ITCKRIST.ttf");

	Text text_return_to_menu("To get to the menu press the key Escape.", font, 26);
	text_return_to_menu.setFillColor(Color(65, 44, 56));
	text_return_to_menu.setStyle(Text::Bold);
	text_return_to_menu.setPosition(120, Window_Height - 43);

	bool is_Menu;
	int user_choice = 0;

	if (player_lose) { is_Menu = false; }
	else is_Menu = true;

	while (player_lose)
	{
		Button_try_again.setColor(Color::White);
		Button_Exit.setColor(Color::White);
		user_choice = 0;
		window.clear(Color::White);


		if (IntRect(280, 180, 250, 100).contains(Mouse::getPosition(window))) { Button_try_again.setColor(Color::Blue); user_choice = 1; }
		if (IntRect(280, 340, 250, 100).contains(Mouse::getPosition(window))) { Button_Exit.setColor(Color::Blue);  user_choice = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (user_choice == 1) { window.close(); return true; }
			if (user_choice == 2) { window.close(); player_lose = false; } //если нажали вторую кнопку, то выходим из меню 
		}

		window.draw(Background_window_menu);//рисуем квадратики на экран
		window.draw(Button_try_again);
		window.draw(Button_Exit);

		window.display();
	}

	while (is_Menu)
	{
		Button_Start.setColor(Color::White);
		Button_Rules.setColor(Color::White);
		Button_Exit.setColor(Color::White);
		user_choice = 0;
		window.clear(Color::White);

		if (IntRect(280, 80, 250, 100).contains(Mouse::getPosition(window))) { Button_Start.setColor(Color::Blue); user_choice = 1; }
		if (IntRect(280, 210, 250, 100).contains(Mouse::getPosition(window))) { Button_Rules.setColor(Color::Blue); user_choice = 2; }
		if (IntRect(280, 340, 250, 100).contains(Mouse::getPosition(window))) { Button_Exit.setColor(Color::Blue);  user_choice = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (user_choice == 1) { is_Menu = false; }
			if (user_choice == 2)
			{
				window.draw(Window_Rules);
				window.draw(text_return_to_menu);
				window.display();
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}
			if (user_choice == 3) { window.close(); is_Menu = false; }
		}

		window.draw(Background_window_menu);//рисуем квадратики на экран
		window.draw(Button_Start);
		window.draw(Button_Rules);
		window.draw(Button_Exit);

		window.display();
	}
}