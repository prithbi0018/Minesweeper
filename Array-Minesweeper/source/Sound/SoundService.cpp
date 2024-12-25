#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"

namespace Sound
{
    using namespace Global;

    void SoundService::initialize()
    {
        loadBackgroundMusicFromFile();
        loadSoundFromFile();
    }

    void SoundService::loadBackgroundMusicFromFile()
    {
        if (!background_music.openFromFile(Config::background_music_path))
        {
            printf("Error loading background music file\n");
        }
    }

    void SoundService::loadSoundFromFile()
    {
        if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
        {
            printf("Error loading button click sound file\n");
        }
        if (!buffer_flag.loadFromFile(Config::flag_sound_path))  
        {
            printf("Error loading flag sound file\n");
        }
    }

    void SoundService::playSound(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BUTTON_CLICK:
            sound_effect.setBuffer(buffer_button_click);
            break;

        case SoundType::FLAG:
            sound_effect.setBuffer(buffer_flag);  
            break;

        default:
            printf("Invalid sound type\n");
            return;
        }

        sound_effect.play();
    }

    void SoundService::playBackgroundMusic()
    {
        background_music.setLoop(true);
        background_music.setVolume(background_music_volume);
        background_music.play();
    }
}
