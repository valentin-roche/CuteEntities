#include "soundmanager.h"

SoundManager::SoundManager()
{
    m_music.setSource(QUrl::fromLocalFile(":/mario.wav"));
    m_music.setLoopCount(5000);

    m_coin.setSource(QUrl::fromLocalFile(":/coin.wav"));
    m_coin.setLoopCount(0);

    m_jump.setSource(QUrl::fromLocalFile(":/jump.wav"));
    m_jump.setLoopCount(0);
}

void SoundManager::play(SoundManager::Sounds sound)
{
    switch (sound) {
        case Sounds::Music:
            m_music.play();
        break;
        case Sounds::Coin:
            m_coin.play();
        break;
        case Sounds::Jump:
            m_jump.play();
        break;
    }
}
