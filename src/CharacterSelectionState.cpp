#include "CharacterSelectionState.hpp"

namespace WappieJump
{
    CharacterSelectionState::CharacterSelectionState(GameDataRef data) : _data(data), _buttonPressSound(_data->assets.GetSound("Button Press"))
    {
    }

    int CharacterSelectionState::AlignObjectCenterX(sf::Sprite object)
    {
        return SCREEN_WIDTH / 2 - object.getGlobalBounds().width / 2;
    }

    int CharacterSelectionState::AlignObjectCenterY(sf::Sprite object)
    {
        return SCREEN_HEIGHT / 2 - object.getGlobalBounds().height / 2;
    }

    void CharacterSelectionState::Init()
    {   
        _data->assets.LoadFont("Font", FONT_FILEPATH);

        _data->assets.LoadTexture("Char1", CHAR1_FILEPATH);
        _data->assets.LoadTexture("Char2", CHAR2_FILEPATH);
        _data->assets.LoadTexture("Char3", CHAR3_FILEPATH);
        _data->assets.LoadTexture("Char4", CHAR4_FILEPATH);
        _data->assets.LoadTexture("Char5", CHAR5_FILEPATH);
        _data->assets.LoadTexture("Char6", CHAR6_FILEPATH);
        _data->assets.LoadTexture("Char7", CHAR7_FILEPATH);
        _data->assets.LoadTexture("Char8", CHAR8_FILEPATH);

        _data->assets.LoadTexture("leftArrow", ARROW_LEFT_FILEPATH);
        _data->assets.LoadTexture("rightArrow", ARROW_RIGHT_FILEPATH);
        _data->assets.LoadTexture("selectButton", SELECT_BUTTON_FILEPATH);
        _data->assets.LoadTexture("homeScreenButton", HOME_SCREEN_BUTTON_FILEPATH);

        _data->assets.LoadTexture("Character Selection Background", CHARACTER_SELECTION_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Character Selection Title", CHARACTER_SELECTION_TITLE_FILEPATH);

        _background.setTexture(_data->assets.GetTexture("Character Selection Background"));

        _char1.setTexture(_data->assets.GetTexture("Char1"));
        _char2.setTexture(_data->assets.GetTexture("Char2"));
        _char3.setTexture(_data->assets.GetTexture("Char3"));
        _char4.setTexture(_data->assets.GetTexture("Char4"));
        _char5.setTexture(_data->assets.GetTexture("Char5"));
        _char6.setTexture(_data->assets.GetTexture("Char6"));
        _char7.setTexture(_data->assets.GetTexture("Char7"));
        _char8.setTexture(_data->assets.GetTexture("Char8"));
        
        _leftArrow.setTexture(_data->assets.GetTexture("leftArrow"));
        _leftArrow.setScale(0.5f, 0.5f);
        _rightArrow.setTexture(_data->assets.GetTexture("rightArrow"));
        _rightArrow.setScale(0.5f, 0.5f);
        _selectButton.setTexture(_data->assets.GetTexture("selectButton"));
        _selectButton.setScale(0.5f, 0.5f);

        _homeButton.setTexture(_data->assets.GetTexture("homeScreenButton"));
        _homeButton.setScale(0.2f, 0.2f);

        _char1.setPosition(AlignObjectCenterX(_char1), AlignObjectCenterY(_char1));
        _char2.setPosition(AlignObjectCenterX(_char2), AlignObjectCenterY(_char2));
        _char3.setPosition(AlignObjectCenterX(_char3), AlignObjectCenterY(_char3));
        _char4.setPosition(AlignObjectCenterX(_char4), AlignObjectCenterY(_char4));
        _char5.setPosition(AlignObjectCenterX(_char5), AlignObjectCenterY(_char5));
        _char6.setPosition(AlignObjectCenterX(_char6), AlignObjectCenterY(_char6));
        _char7.setPosition(AlignObjectCenterX(_char7), AlignObjectCenterY(_char7));
        _char8.setPosition(AlignObjectCenterX(_char8), AlignObjectCenterY(_char8));

        _basePositionY = _char1.getPosition().y;

        _leftArrow.setPosition(AlignObjectCenterX(_leftArrow) - 100, AlignObjectCenterY(_leftArrow));
        _rightArrow.setPosition(AlignObjectCenterX(_rightArrow) + 100, AlignObjectCenterY(_rightArrow));
        _selectButton.setPosition(AlignObjectCenterX(_selectButton), AlignObjectCenterY(_selectButton) + 150); // change position
        _homeButton.setPosition(SCREEN_WIDTH * 0.87, SCREEN_HEIGHT * 0.9);
    }

    void CharacterSelectionState::BounceCharacter()
    {
        if (_chars[_selected] != &_selectedCharacter)
        {
            _chars[_selected]->setPosition(_selectedCharacter.getPosition());
            _selectedCharacter = *_chars[_selected];
        }
        if (_selectedCharacter.getPosition().y >= _basePositionY) _characterVelocityY = -PLAYER_VELOCITY_Y * 0.7f;
        
       _selectedCharacter.move(0.0f, _characterVelocityY);
        _characterVelocityY += GRAVITY;
    }

    void CharacterSelectionState::HandleInput()
    {
        sf::Event event;

        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _data->window.close();
            }

            if (_data->input.IsSpriteClicked(_rightArrow, sf::Mouse::Left, _data->window) || _data->input.IsSpriteClicked(_leftArrow, sf::Mouse::Left, _data->window))
            {
                mouseClicked = true;
            }

            if (_data->input.IsSpriteClicked(_rightArrow, sf::Mouse::Left, _data->window) && mouseClicked)
            {
                mouseClicked = false;
                _selected == 7 ? _selected = 0 : _selected += 1;
            }
            
            if (_data->input.IsSpriteClicked(_leftArrow, sf::Mouse::Left, _data->window) && mouseClicked)
            {
                mouseClicked = false;
                _selected == 0 ? _selected = 7 : _selected -= 1;
            }

            if (_data->input.IsSpriteClicked(_selectButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))  
            {
                _data->characterSprite = *_chars[_selected];
                _buttonPressSound.play();
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            if (_data->input.IsSpriteClicked(_homeButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				// Switch To Main Menu
                _buttonPressSound.play();
				_data->machine.AddState(StateRef(new SettingState(_data)), true);
			}
        }
    }

    void CharacterSelectionState::Update()
    {
        BounceCharacter();
    }

    void CharacterSelectionState::Draw()
    {
        _data->window.clear(sf::Color::White);

        _data->window.draw(_background);
        _data->window.draw(_selectButton);
        _data->window.draw(_homeButton);
        _data->window.draw(_leftArrow);
        _data->window.draw(_rightArrow);
        _data->window.draw(*_chars[_selected]);
        _data->window.display();
    }
}