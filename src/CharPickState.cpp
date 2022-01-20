#include "CharPickState.hpp"

namespace Sonar
{
    CharPickState::CharPickState(GameDataRef data) : _data(data)
    {
    }

    void CharPickState::Init()
    {
        _data->assets.LoadTexture("Char1", CHAR1_FILEPATH);
        _data->assets.LoadTexture("Char2", CHAR2_FILEPATH);
        _data->assets.LoadTexture("Char3", CHAR3_FILEPATH);
        _data->assets.LoadTexture("Char4", CHAR4_FILEPATH);
        _data->assets.LoadTexture("Char5", CHAR5_FILEPATH);
        _data->assets.LoadTexture("Char6", CHAR6_FILEPATH);
        _data->assets.LoadTexture("Char7", CHAR7_FILEPATH);
        _data->assets.LoadTexture("Char8", CHAR8_FILEPATH);
        std::cout << "chars loaded\n";

        _data->assets.LoadTexture("leftArrow", ARROW_LEFT_FILEPATH);
        _data->assets.LoadTexture("rightArrow", ARROW_RIGHT_FILEPATH);
        std::cout << "arrows loaded\n";

        _background.setTexture(_data->assets.GetTexture("Game Background"));
        std::cout << "main menu set\n";

        _title.setTexture(_data->assets.GetTexture("Game Title"));
        std::cout << "title set\n";
        
        _char1.setTexture(_data->assets.GetTexture("Char1"));
        _char2.setTexture(_data->assets.GetTexture("Char2"));
        _char3.setTexture(_data->assets.GetTexture("Char3"));
        _char4.setTexture(_data->assets.GetTexture("Char4"));
        _char5.setTexture(_data->assets.GetTexture("Char5"));
        _char6.setTexture(_data->assets.GetTexture("Char6"));
        _char7.setTexture(_data->assets.GetTexture("Char7"));
        _char8.setTexture(_data->assets.GetTexture("Char8"));
        std::cout << "chars set\n";

        _leftArrow.setTexture(_data->assets.GetTexture("leftArrow"));
        _rightArrow.setTexture(_data->assets.GetTexture("rightArrow"));
        std::cout << "arrows set\n";
        // _selectButton.setTexture(_data->assets.GetTexture("selectButton"));

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
        // _selectButton.setPosition((SCREEN_WIDTH / 2) - (_selectButton.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2);
    }

    void CharPickState::HandleInput()
    {
        sf::Event event;

        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }

            if (_data->input.IsSpriteClicked(_char1, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR1_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR1MIR_FILEPATH);

                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            else if (_data->input.IsSpriteClicked(_char2, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR2_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR2MIR_FILEPATH);

                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            else if (_data->input.IsSpriteClicked(_char3, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR3_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR3MIR_FILEPATH);

                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            else if (_data->input.IsSpriteClicked(_char4, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR4_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR4MIR_FILEPATH);

                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            else if (_data->input.IsSpriteClicked(_char5, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR5_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR5MIR_FILEPATH);

                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            else if (_data->input.IsSpriteClicked(_char6, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR6_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR6MIR_FILEPATH);

                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            else if (_data->input.IsSpriteClicked(_char7, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR7_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR7MIR_FILEPATH);

                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            else if (_data->input.IsSpriteClicked(_char8, sf::Mouse::Left, _data->window))
            {
                _data->assets.LoadTexture("Player", CHAR8_FILEPATH);
                _data->assets.LoadTexture("Player Mirrored", CHAR8MIR_FILEPATH);
                // Switch To Main Menu
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }

            // sf::Event event;

            // while (_data->window.pollEvent(event))
            // {
            // 	if (sf::Event::Closed == event.type)
            // 	{
            // 		_data->window.close();
            // 	}
            // }
        }
    }

    void CharPickState::Update(float dt)
    {
    }

    void CharPickState::Draw(float dt)
    {
        _data->window.clear(sf::Color::White);

        _data->window.draw(_background);
        _data->window.draw(_title);
        // _data->window.draw(_char1);
        // _data->window.draw(_char2);
        // _data->window.draw(_char3);
        // _data->window.draw(_char4);
        // _data->window.draw(_char5);
        // _data->window.draw(_char6);
        // _data->window.draw(_char7);
        // _data->window.draw(_char8);
        _data->window.draw(chars[_selected]);
        _data->window.display();
    }
}