#include <Ada_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

#define NUMFLAKES 10 // Number of snowflakes in the animation example
#define SSD1306_NO_SPLASH 0
#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16
static const unsigned char PROGMEM logo_bmp[] =
    {0b00000000, 0b11000000,
     0b00000001, 0b11000000,
     0b00000001, 0b11000000,
     0b00000011, 0b11100000,
     0b11110011, 0b11100000,
     0b11111110, 0b11111000,
     0b01111110, 0b11111111,
     0b00110011, 0b10011111,
     0b00011111, 0b11111100,
     0b00001101, 0b01110000,
     0b00011011, 0b10100000,
     0b00111111, 0b11100000,
     0b00111111, 0b11110000,
     0b01111100, 0b11110000,
     0b01110000, 0b01110000,
     0b00000000, 0b00110000};

void testdrawline()
{
    int16_t i;

    display1.clearDisplay(); // Clear display buffer

    for (i = 0; i < display1.width(); i += 4)
    {
        display1.drawLine(0, 0, i, display1.height() - 1, SSD1306_WHITE);
        display1.display(); // Update screen with each newly-drawn line
        delay(1);
    }
    for (i = 0; i < display1.height(); i += 4)
    {
        display1.drawLine(0, 0, display1.width() - 1, i, SSD1306_WHITE);
        display1.display();
        delay(1);
    }
    delay(250);

    display1.clearDisplay();

    for (i = 0; i < display1.width(); i += 4)
    {
        display1.drawLine(0, display1.height() - 1, i, 0, SSD1306_WHITE);
        display1.display();
        delay(1);
    }
    for (i = display1.height() - 1; i >= 0; i -= 4)
    {
        display1.drawLine(0, display1.height() - 1, display1.width() - 1, i, SSD1306_WHITE);
        display1.display();
        delay(1);
    }
    delay(250);

    display1.clearDisplay();

    for (i = display1.width() - 1; i >= 0; i -= 4)
    {
        display1.drawLine(display1.width() - 1, display1.height() - 1, i, 0, SSD1306_WHITE);
        display1.display();
        delay(1);
    }
    for (i = display1.height() - 1; i >= 0; i -= 4)
    {
        display1.drawLine(display1.width() - 1, display1.height() - 1, 0, i, SSD1306_WHITE);
        display1.display();
        delay(1);
    }
    delay(250);

    display1.clearDisplay();

    for (i = 0; i < display1.height(); i += 4)
    {
        display1.drawLine(display1.width() - 1, 0, 0, i, SSD1306_WHITE);
        display1.display();
        delay(1);
    }
    for (i = 0; i < display1.width(); i += 4)
    {
        display1.drawLine(display1.width() - 1, 0, i, display1.height() - 1, SSD1306_WHITE);
        display1.display();
        delay(1);
    }

    delay(2000); // Pause for 2 seconds
}

void testdrawrect(void)
{
    display1.clearDisplay();

    for (int16_t i = 0; i < display1.height() / 2; i += 2)
    {
        display1.drawRect(i, i, display1.width() - 2 * i, display1.height() - 2 * i, SSD1306_WHITE);
        display1.display(); // Update screen with each newly-drawn rectangle
        delay(1);
    }

    delay(2000);
}

void testfillrect(void)
{
    display1.clearDisplay();

    for (int16_t i = 0; i < display1.height() / 2; i += 3)
    {
        // The INVERSE color is used so rectangles alternate white/black
        display1.fillRect(i, i, display1.width() - i * 2, display1.height() - i * 2, SSD1306_INVERSE);
        display1.display(); // Update screen with each newly-drawn rectangle
        delay(1);
    }

    delay(2000);
}

void testdrawcircle(void)
{
    display1.clearDisplay();

    for (int16_t i = 0; i < max(display1.width(), display1.height()) / 2; i += 2)
    {
        display1.drawCircle(display1.width() / 2, display1.height() / 2, i, SSD1306_WHITE);
        display1.display();
        delay(1);
    }

    delay(2000);
}

void testfillcircle(void)
{
    display1.clearDisplay();

    for (int16_t i = max(display1.width(), display1.height()) / 2; i > 0; i -= 3)
    {
        // The INVERSE color is used so circles alternate white/black
        display1.fillCircle(display1.width() / 2, display1.height() / 2, i, SSD1306_INVERSE);
        display1.display(); // Update screen with each newly-drawn circle
        delay(1);
    }

    delay(2000);
}

void testdrawroundrect(void)
{
    display1.clearDisplay();

    for (int16_t i = 0; i < display1.height() / 2 - 2; i += 2)
    {
        display1.drawRoundRect(i, i, display1.width() - 2 * i, display1.height() - 2 * i,
                               display1.height() / 4, SSD1306_WHITE);
        display1.display();
        delay(1);
    }

    delay(2000);
}

void testfillroundrect(void)
{
    display1.clearDisplay();

    for (int16_t i = 0; i < display1.height() / 2 - 2; i += 2)
    {
        // The INVERSE color is used so round-rects alternate white/black
        display1.fillRoundRect(i, i, display1.width() - 2 * i, display1.height() - 2 * i,
                               display1.height() / 4, SSD1306_INVERSE);
        display1.display();
        delay(1);
    }

    delay(2000);
}

void testdrawtriangle(void)
{
    display1.clearDisplay();

    for (int16_t i = 0; i < max(display1.width(), display1.height()) / 2; i += 5)
    {
        display1.drawTriangle(
            display1.width() / 2, display1.height() / 2 - i,
            display1.width() / 2 - i, display1.height() / 2 + i,
            display1.width() / 2 + i, display1.height() / 2 + i, SSD1306_WHITE);
        display1.display();
        delay(1);
    }

    delay(2000);
}

void testfilltriangle(void)
{
    display1.clearDisplay();

    for (int16_t i = max(display1.width(), display1.height()) / 2; i > 0; i -= 5)
    {
        // The INVERSE color is used so triangles alternate white/black
        display1.fillTriangle(
            display1.width() / 2, display1.height() / 2 - i,
            display1.width() / 2 - i, display1.height() / 2 + i,
            display1.width() / 2 + i, display1.height() / 2 + i, SSD1306_INVERSE);
        display1.display();
        delay(1);
    }

    delay(2000);
}

void testdrawchar(void)
{
    display1.clearDisplay();

    display1.setTextSize(1);              // Normal 1:1 pixel scale
    display1.setTextColor(SSD1306_WHITE); // Draw white text
    display1.setCursor(0, 0);             // Start at top-left corner
    // display1.cp437(true);                 // Use full 256 char 'Code Page 437' font

    // Not all the characters will fit on the display. This is normal.
    // Library will draw what it can and the rest will be clipped.
    for (int16_t i = 0; i < 256; i++)
    {
        if (i == '\n')
            display1.write(' ');
        else
            display1.write(i);
    }

    display1.display();
    delay(2000);
}

void testdrawstyles(void)
{
    display1.clearDisplay();

    display1.setTextSize(1);              // Normal 1:1 pixel scale
    display1.setTextColor(SSD1306_WHITE); // Draw white text
    display1.setCursor(0, 0);             // Start at top-left corner
    display1.println(F("Hello, world!"));

    display1.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
    display1.println(3.141592);

    display1.setTextSize(2); // Draw 2X-scale text
    display1.setTextColor(SSD1306_WHITE);
    display1.print(F("0x"));
    display1.println(0xDEADBEEF, HEX);

    display1.display();
    delay(2000);
}

void testscrolltext(void)
{
    display1.clearDisplay();

    display1.setTextSize(2); // Draw 2X-scale text
    display1.setTextColor(SSD1306_WHITE);
    display1.setCursor(10, 0);
    display1.println(F("scroll"));
    display1.display(); // Show initial text
    delay(100);

    // Scroll in various directions, pausing in-between:
    display1.startscrollright(0x00, 0x0F);
    delay(2000);
    display1.stopscroll();
    delay(1000);
    display1.startscrollleft(0x00, 0x0F);
    delay(2000);
    display1.stopscroll();
    delay(1000);
    display1.startscrolldiagright(0x00, 0x07);
    delay(2000);
    display1.startscrolldiagleft(0x00, 0x07);
    delay(2000);
    display1.stopscroll();
    delay(1000);
}

void testdrawbitmap(void)
{
    display1.clearDisplay();

    display1.drawBitmap(
        (display1.width() - LOGO_WIDTH) / 2,
        (display1.height() - LOGO_HEIGHT) / 2,
        logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
    display1.display();
    delay(1000);
}

#define XPOS 0 // Indexes into the 'icons' array in function below
#define YPOS 1
#define DELTAY 2

void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h)
{
    int8_t f, icons[NUMFLAKES][3];

    // Initialize 'snowflake' positions
    for (f = 0; f < NUMFLAKES; f++)
    {
        icons[f][XPOS] = random(1 - LOGO_WIDTH, display1.width());
        icons[f][YPOS] = -LOGO_HEIGHT;
        icons[f][DELTAY] = random(1, 6);
        Serial.print(F("x: "));
        Serial.print(icons[f][XPOS], DEC);
        Serial.print(F(" y: "));
        Serial.print(icons[f][YPOS], DEC);
        Serial.print(F(" dy: "));
        Serial.println(icons[f][DELTAY], DEC);
    }

    for (;;)
    {                            // Loop forever...
        display1.clearDisplay(); // Clear the display buffer

        // Draw each snowflake:
        for (f = 0; f < NUMFLAKES; f++)
        {
            display1.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
        }

        display1.display(); // Show the display buffer on the screen
        delay(200);         // Pause for 1/10 second

        // Then update coordinates of each flake...
        for (f = 0; f < NUMFLAKES; f++)
        {
            icons[f][YPOS] += icons[f][DELTAY];
            // If snowflake is off the bottom of the screen...
            if (icons[f][YPOS] >= display1.height())
            {
                // Reinitialize to a random position, just off the top
                icons[f][XPOS] = random(1 - LOGO_WIDTH, display1.width());
                icons[f][YPOS] = -LOGO_HEIGHT;
                icons[f][DELTAY] = random(1, 6);
            }
        }
    }
}

void setup()
{
    Serial.begin(115200);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display1.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display1.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    display1.clearDisplay();

    // Draw a single pixel in white
    display1.drawPixel(10, 10, SSD1306_WHITE);

    // Show the display buffer on the screen. You MUST call display1() after
    // drawing commands to make them visible on screen!
    display1.display();
    delay(2000);
    // display.display() is NOT necessary after every single drawing command,
    // unless that's what you want...rather, you can batch up a bunch of
    // drawing operations and then update the screen all at once by calling
    // display.display(). These examples demonstrate both approaches...

    testdrawline(); // Draw many lines

    testdrawrect(); // Draw rectangles (outlines)

    testfillrect(); // Draw rectangles (filled)

    testdrawcircle(); // Draw circles (outlines)

    testfillcircle(); // Draw circles (filled)

    testdrawroundrect(); // Draw rounded rectangles (outlines)

    testfillroundrect(); // Draw rounded rectangles (filled)

    testdrawtriangle(); // Draw triangles (outlines)

    testfilltriangle(); // Draw triangles (filled)

    testdrawchar(); // Draw characters of the default font

    testdrawstyles(); // Draw 'stylized' characters

    testscrolltext(); // Draw scrolling text

    testdrawbitmap(); // Draw a small bitmap image

    // Invert and restore display, pausing in-between
    display1.invertDisplay(true);
    delay(1000);
    display1.invertDisplay(false);
    delay(1000);

    testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animate bitmaps
}

void loop()
{
}
