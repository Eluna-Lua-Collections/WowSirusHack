#include "Menu.h"

void Menu::ToggleStateMenu()
{
	this->state = !this->state;
}


void Menu::DrawMenu(int& AddToSpeed, bool& isActive)
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor;


	ImGui::Begin("project 22", NULL, 0);
	ImGui::Checkbox("SpeedHack", &isActive);
	ImGui::SliderInt("Speed", &AddToSpeed, 0, 100);
	ImGui::BeginTabBar("Tabbar");
	ImGui::EndTabBar();

	ImGui::BeginMainMenuBar();
	ImGui::Text("Coded by ");
	ImGui::Button("Mediocrity");
	ImGui::EndMainMenuBar();


	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

BOOL Menu::GetStateMenu()
{
	return this->state;
}
