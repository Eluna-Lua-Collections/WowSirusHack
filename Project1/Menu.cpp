#include "Menu.h"
int choose;
int choose1;

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
	if (ImGui::Button("q1q1q1q1q1q1q1 :)"))
		ShellExecute(NULL, L"open", L"https://github.com/q1q1q1q1q1q1q1", NULL, NULL, SW_SHOW);
	ImGui::EndMainMenuBar();
	
	if (ImGui::CollapsingHeader("Calimdor"))
	{
		if (ImGui::CollapsingHeader("Durotar"))
		{
			ImGui::Combo("Durotar", &choose, "Prickly hill");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(299.766f, -4738.79f, 9.34871f);
			}
		}

		if (ImGui::CollapsingHeader("Lunnaya Polyana"))
		{
			ImGui::Combo("Lunnaya Polyana", &choose, "Lake Elune'ara");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(7471.42f, -2123.11f, 492.343f);
			}
		}

		if (ImGui::CollapsingHeader("Winter keys"))
		{
			ImGui::Combo("Winter keys", &choose, "Horizon");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(6808.32f, -4606.15f, 710.436f);
			}
		}

		if (ImGui::CollapsingHeader("Felwood"))
		{
			ImGui::Combo("Felwood  ", &choose, "Poisoned blood Outpost \0The emerald sanctuary");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(5067.36f, -338.111f, 367.363f);
				if (choose == 1)
					Teleport(3982.12f, -1320.65f, 251.08f);
			}
		}

		if (ImGui::CollapsingHeader("Ash wood"))
		{
			ImGui::Combo("Ash wood ", &choose, "Split tree Outpost \0Zoram'gar Fort");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(2305.64f, -2522.21f, 104.026f);
				if (choose == 1)
					Teleport(3373.95f, 999.349f, 5.08524f);
			}
		}

		if (ImGui::CollapsingHeader("Steppes"))
		{
			ImGui::Combo("Steppes ", &choose, "Camp Taurajo \0Kabestan \0Crossroad");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(-2379.96f, -1881.45f, 95.8504f);
				if (choose == 1)
					Teleport(-893.765f, -3774.79f, 11.5232f);
				if (choose == 2)
					Teleport(-439.2f, 2598.95f, 95.8345f);
			}
		}

		if (ImGui::CollapsingHeader("Bony mountains"))
		{
			ImGui::Combo("Bony mountains ", &choose, "Shelter with solar stone");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(967.934f, 1042.23f, 104.365f);
			}
		}

		if (ImGui::CollapsingHeader("Wastelands"))
		{
			ImGui::Combo("Wastelands ", &choose, "Village of night hunters");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-1771.67f, 3265.97f, 5.12719f);
			}
		}

		if (ImGui::CollapsingHeader("Mulgor"))
		{
			ImGui::Combo("Mulgor ", &choose, "Thunder cliff");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-1197.88f, 27.3044f, 176.949f);
			}
		}

		if (ImGui::CollapsingHeader("Feralas"))
		{
			ImGui::Combo("Feralas ", &choose, "Mohache Camp");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-4420.69f, 198.635f, 25.0628f);
			}
		}

		if (ImGui::CollapsingHeader("Thousand Needles"))
		{
			ImGui::Combo("Thousand Needles ", &choose, "Free Wind Outpost");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-5409.91f, -2416.69f, 90.019f);
			}
		}

		if (ImGui::CollapsingHeader("Tanaris"))
		{
			ImGui::Combo("Thousand Needles ", &choose, "Pribambassk");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-7049.33f, -3780.4f, 10.1851f);
			}
		}

		if (ImGui::CollapsingHeader("Un'goro Crater"))
		{
			ImGui::Combo("Un'goro Crater ", &choose, "Marshall's Hideout");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-6113.0f, -1143.6f, -187.49f);
			}
		}


		if (ImGui::CollapsingHeader("Silithus"))
		{
			ImGui::Combo("Silithus ", &choose, "Cenaria Fortress");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-6811.54f, 836.713f, 49.8104f);
			}
		}

		if (ImGui::CollapsingHeader("Dust swamps"))
		{
			ImGui::Combo("Dust swamps ", &choose, "Village Giblotop'");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-3145.22f, -2842.41f, 34.6252f);
			}
		}

		if (ImGui::CollapsingHeader("Azshara"))
		{
			ImGui::Combo("Azshara ", &choose, "Hrabrostan'");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(3663.94f, -4391.5f, 113.055f);
			}
		}
	}

	if (ImGui::CollapsingHeader("Beyond"))
	{
		if (ImGui::CollapsingHeader("The Hellfire Peninsula"))
		{
			ImGui::Combo("The Hellfire Peninsula ", &choose, "Thrallmar \0Falcon watch");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(178.192f, 2627.32f, 87.127f);
				if (choose == 1)
					Teleport(-610.221f, 4096.47f, 91.0206f);
			}
		}

		if (ImGui::CollapsingHeader("Pistovert'"))
		{
			ImGui::Combo("Pistovert' ", &choose, "Zone 52\0Kosmovorot \0Storm Peak");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(3064.85f, 3667.17f, 142.197f);
				if (choose == 1)
					Teleport(2979.69f, 1848.81f, 141.848f);
				if (choose == 2)
					Teleport(4116.47f, 2972.36f, 351.992f);
			}
		}

		if (ImGui::CollapsingHeader("Ostrogor'e"))
		{
			ImGui::Combo("Ostrogor'e ", &choose, "Thickets Ruuan \0Oplot Gromoborchew");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(2973.37f, 5504.32f, 143.58f);
				if (choose == 1)
					Teleport(2445.97f, 6016.41f, 154.257f);
			}
		}

		if (ImGui::CollapsingHeader("Zangartop'"))
		{
			ImGui::Combo("Zangartop' ", &choose, "Swamp rat Outpost \0Zabradzin");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(91.6521f, 5214.39f, 23.0794f);
				if (choose == 1)
					Teleport(221.447f, 7815.63f, 22.7285f);
			}
		}

		if (ImGui::CollapsingHeader("Terokkar Forest"))
		{
			ImGui::Combo("Terokkar Forest ", &choose, "Shattrath \0Fort Kamnelomov");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(-1813.62f, 5311.83f, -12.4278f);
				if (choose == 1)
					Teleport(-2567.0f, 4425.01f, 39.3062f);
			}
		}

		if (ImGui::CollapsingHeader("Nagrand"))
		{
			ImGui::Combo("Nagrand ", &choose, "Garadar'");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(-1265.02f, 7135.47f, 57.4037f);
			}
		}


		if (ImGui::CollapsingHeader("Ghost moon valley"))
		{
			ImGui::Combo("Ghost moon valley ", &choose, "Ghost moon valley \0Altar Shatar \0Sanctuary of the stars");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(-3014.38f, 2567.64f, 78.0838f);
				if (choose == 1)
					Teleport(-3062.9f, 741.49f, -10.1459f);
				if (choose == 2)
					Teleport(-4070.11f, 1125.71f, 42.7574f);
			}
		}
	}

	if (ImGui::CollapsingHeader("Nordskol"))
	{
		if (ImGui::CollapsingHeader("Roaring Fjord"))
		{
			ImGui::Combo("Roaring Fjord ", &choose, "Retribution camp \0New agamand \0Camp covered Hoofs \0Pharmaceutical settlement");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(1938.62f, -6168.05f, 23.6999f);
				if (choose == 1)
					Teleport(400.056f, -4543.68f, 244.769f);
				if (choose == 2)
					Teleport(2651.23f, -4393.98f, 283.305f);
				if (choose == 3)
					Teleport(2106.73f, 2106.73f, 148.584f);
			}
		}
		if (ImGui::CollapsingHeader("Grey hills"))
		{
			ImGui::Combo("Grey hills ", &choose, "Camp Uankva \0Fortress of the conquerors");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(3876.64f, -4516.79f, 216.739f);
				if (choose == 1)
					Teleport(3255.74f, -2262.77f, 114.534f);
			}
		}
		if (ImGui::CollapsingHeader("ZulDrak"))
		{
			ImGui::Combo("ZulDrak ", &choose, "Silver Outpost");
			if (ImGui::Button("Teleporting"))
			{
				Teleport(5519.42f, -2671.33f, 303.954f);
			}
		}

		if (ImGui::CollapsingHeader("Graveyard Of The Dragon"))
		{
			ImGui::Combo("Graveyard Of The Dragon ", &choose, "Yadozlob' \0Agmar's Hammer \0Ice Crown");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(3243.99, -665.371f, 166.789f);
				if (choose == 1)
					Teleport(3807.1f, 1539.1f, 89.7247f);
				if (choose == 2)
					Teleport(4937.71f, 1169.33f, 238.932f);
			}
		}

		if (ImGui::CollapsingHeader("Crystal Song Forest"))
		{
			ImGui::Combo("Crystal Song Forest ", &choose, "The camp of the thief of the sun \0Dalaran");
			if (ImGui::Button("Teleporting"))
			{
				if (choose == 0)
					Teleport(5591.05f, -694.714f, 206.627f);
				if (choose == 1)
					Teleport(5855.64f, 618.352f, 649.757f);
			}
		}
	}
	
	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

BOOL Menu::GetStateMenu()
{
	return this->state;
}
