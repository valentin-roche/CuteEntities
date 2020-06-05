#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QSoundEffect>

class SoundManager {

public:
    enum Sounds {
        Music,
        Jump,
        Coin
    };

    SoundManager();
    void play(Sounds sound);

private:
    QSoundEffect m_music;
    QSoundEffect m_jump;
    QSoundEffect m_coin;
};

#endif // SOUNDMANAGER_H
