//
// Created by Эрик on 06.05.2021.
//

#ifndef NIBBLES_01_CLASS_H
#define NIBBLES_01_CLASS_H
class Igrok {


public:

    float x, y;
    float  w, h, dx, dy, speed;
    int dir, score, bubble, health,ss;
    bool life;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;
    Igrok(String F, float X, float Y, float W, float H) {
        dx = 0; dy = 0; speed = 0; dir = 0; score = 0; health = 5; bubble = 0; ss = 0;
        bool life;
        File = F;
        w = W; h = H;
        image.loadFromFile("images/" + File);
        image.createMaskFromColor(Color(41, 33, 59));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }

    void update(float time)
    {
        if (health <= 0) { life = false; speed = 0; }
        switch (dir)
        {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed; break;
            case 3: dx = 0; dy = -speed; break;
        }

        x += dx * time;
        y += dy * time;
        interactionWithMap();
        if (bubble != 1)
            speed = 0;

        sprite.setPosition(x, y);

        if (health <= 0) { life = false; speed = 0; }
    }

    void interactionWithMap()
    {

        for (int i = y / 32; i < (y + h) / 32; i++)
            for (int j = x / 32; j < (x + w) / 32; j++)
            {
                if (TMap[i][j] == '0' || TMap[i][j] == 'k')
                {
                    if (dy > 0)
                    {
                        y = i * 32 - h;
                    }
                    if (dy < 0)
                    {
                        y = i * 32 + 32;
                    }
                    if (dx > 0)
                    {
                        x = j * 32 - w;
                    }
                    if (dx < 0)
                    {
                        x = j * 32 + 32;
                    }
                }

                if (TMap[i][j] == 's')
                {
                    score++;
                    ss++;
                    health = health + 1 - 1;
                    TMap[i][j] = ' ';
                }
                if (TMap[i][j] == 'l')
                {
                    health -= 1;
                    TMap[i][j] = ' ';
                }
                if (TMap[i][j] == 'r')
                {
                    health += score;
                    score = 0;


                }
                bubble = 0;
                if (TMap[i][j] == 'f')
                {
                    bubble = 1;


                }

            }
    }
};


#endif //NIBBLES_01_CLASS_H
