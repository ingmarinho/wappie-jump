#include "CharacterSelectionState.hpp"

namespace WappieJump
{
    CharacterSelectionState::CharacterSelectionState(GameDataRef data) : _data(data)
    {
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

        _data->assets.LoadTexture("Character Selection Background", CHARACTER_SELECTION_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Character Selection Title", CHARACTER_SELECTION_TITLE_FILEPATH);

        _background.setTexture(_data->assets.GetTexture("Character Selection Background"));
        _title.setTexture(_data->assets.GetTexture("Character Selection Title"));

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

        _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height * 2);
        _char1.setPosition((SCREEN_WIDTH / 2) - (_char1.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char1.getGlobalBounds().height / 2));
        _char2.setPosition((SCREEN_WIDTH / 2) - (_char2.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char2.getGlobalBounds().height / 2));
        _char3.setPosition((SCREEN_WIDTH / 2) - (_char3.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char3.getGlobalBounds().height / 2));
        _char4.setPosition((SCREEN_WIDTH / 2) - (_char4.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char4.getGlobalBounds().height / 2));
        _char5.setPosition((SCREEN_WIDTH / 2) - (_char5.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char5.getGlobalBounds().height / 2));
        _char6.setPosition((SCREEN_WIDTH / 2) - (_char6.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char6.getGlobalBounds().height / 2));
        _char7.setPosition((SCREEN_WIDTH / 2) - (_char7.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char7.getGlobalBounds().height / 2));
        _char8.setPosition((SCREEN_WIDTH / 2) - (_char8.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_char8.getGlobalBounds().height / 2));

        _leftArrow.setPosition((SCREEN_WIDTH * 0.25) - (_leftArrow.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_leftArrow.getGlobalBounds().height / 2));
        _rightArrow.setPosition((SCREEN_WIDTH * 0.75) - (_rightArrow.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 - (_rightArrow.getGlobalBounds().height / 2));
        _selectButton.setPosition((SCREEN_WIDTH / 2) - (_selectButton.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2 + (_selectButton.getGlobalBounds().height)); // change position
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
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void CharacterSelectionState::Update()
    {
        // *_chars[_selected]->setColor(sf::Color::Red);
    }

    void CharacterSelectionState::Draw()
    {
        _data->window.clear(sf::Color::White);

        _data->window.draw(_background);
        _data->window.draw(_selectButton);
        _data->window.draw(_leftArrow);
        _data->window.draw(_rightArrow);
        _data->window.draw(*_chars[_selected]);
        _data->window.display();
    }
}