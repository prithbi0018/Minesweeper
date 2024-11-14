#pragma once


namespace Gameplay
{
    namespace Board
    {
        class BoardView;

        class BoardController
        {
        public:
            static const int number_of_rows = 9;
            static const int number_of_colums = 9;
            static const int mines_count = 8;

            BoardController();
            ~BoardController();

            void initialize();
            void update();
            void render();
            void reset();

        private:
            BoardView* board_view;
            void createBoard();
            void destroy();
            void deleteBoard();


        };
    }
}   