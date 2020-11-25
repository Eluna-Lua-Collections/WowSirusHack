#include "Menu.h"

void Menu::ToggleStateMenu()
{
	this->state = !this->state;
}


void Menu::DrawMenu(int& AddToSpeed)
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor;


	ImGui::Begin("project 22", NULL, 0);
	ImGui::SliderInt("Speed", &AddToSpeed, 0, 100);

	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

BOOL Menu::GetStateMenu()
{
	return this->state;
}
