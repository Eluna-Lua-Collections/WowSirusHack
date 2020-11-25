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
	if (ImGui::Button("q1q1q1q1q1q1q1"))
		ShellExecute(NULL, L"open", L"https://github.com/q1q1q1q1q1q1q1", NULL, NULL, SW_SHOW);
	ImGui::EndMainMenuBar();


	if (ImGui::CollapsingHeader("Ogrimmar"))
	{
		ImGui::Button("Teleporting");
	}
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::CollapsingHeader("Ïóñòîø");
	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

BOOL Menu::GetStateMenu()
{
	return this->state;
}
