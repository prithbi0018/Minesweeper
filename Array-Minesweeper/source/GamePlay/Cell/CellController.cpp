#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Cell
	{
		using namespace Global;
		using namespace Sound;

		CellController::CellController(sf::Vector2i position)
		{
			cell_view = new CellView(this);
			cell_model = new CellModel(position);
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize(float cell_width, float cell_height)
		{
			cell_view->initialize(cell_width, cell_height);
		}

		void CellController::update()
		{
			cell_view->update();

		}

		void CellController::render()
		{
			cell_view->render();
		}

		void CellController::destroy()
		{
			delete (cell_view);
			delete (cell_model);
		}
		CellState CellController::getCellState()
		{
			return cell_model->getCellState();
		}
		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}
		void CellController::reset()
		{
			cell_model->reset();
		}	
		sf::Vector2i CellController::getCellPosition()
		{
			return cell_model->getCellPosition();
		}
	}
}