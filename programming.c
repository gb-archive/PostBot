void draw_instructions() {
  
  
  //16 is first arrow tile in 'background.tiles'
  //programming[19] = 16;
  
  //20x18
  unsigned char first_tile_location = 12;
  
  int counter = 0;
  
  for (; counter < 20; counter++) {
	int col = counter % 5;
	int row = counter / 5;
	
	int base_tile = first_tile_location + (program[counter] * 4);
	
    int topleft = ((col * 3) + 63) + (row * 60);
	int topright = topleft + 1;
	int bottomleft = topleft + 20;
	int bottomright = bottomleft + 1;
	
	if (counter >= 10) {
	  topleft += 20;
	  topright += 20;
	  bottomleft += 20;
	  bottomright += 20;
	}
	
	if (counter >= 15) {
	  topleft += 20;
	  topright += 20;
	  bottomleft += 20;
	  bottomright += 20;
	}
	
	if (program[counter] == 0) {
	  current_level[topleft] = 0;
	  current_level[topright] = 0;
	  current_level[bottomleft] = 0;
	  current_level[bottomright] = 0;
	} else {
	  current_level[topleft] = base_tile;
	  current_level[topright] = base_tile + 1;
	  current_level[bottomleft] = base_tile + 2;
	  current_level[bottomright] = base_tile + 3;
	}
  }
  
  //update background
  set_bkg_tiles(0, 0, 20, 18, current_level);
}

void update_programming() {
  if(cursor_update())
    draw_instructions();
}

void init_programming() {
  DISPLAY_OFF;
  screen = 3;
  reset_sprites();
  display_programming();
  draw_instructions();
  cursor_init();
  DISPLAY_ON;
}

void set_command(int row, int col, char dir) {
  int program_location = (row * 5) + col;
  
  //cycling
  if (program[program_location] == 6 && dir > 0)
	program[program_location] = 0;
  else if (program[program_location] == 0 && dir < 0)
	program[program_location] = 6;
  else
    program[program_location] = program[program_location] + dir;
}

/*
 0 empty
 1 forward
 2 turnleft
 3 turnright
 4 transmit
 5 function 1
 6 function 2
*/

/*
  0-09 main program
 10-14 function 1
 15-19 function 2
*/
