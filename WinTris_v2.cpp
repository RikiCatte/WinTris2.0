#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char mappa[4][5] = {
	"#123",
	"1   ",
	"2   ",
	"3   "
};

void StampaMappa()
{
	cout << endl;

	for (int i = 0; i < 4; i++)
		cout << mappa[i] << endl;
}

void AggiornaGiocatore1(char mappa[][5])
{
	int x1, x2, c = 0;

	do
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
			{
				if (mappa[i][j] == ' ')
					c++;
			}

		if (c != 0) //mappa non completa
		{
		errore: //flag goto
			cout << "\nInserisci le coordinate x e y di una casella vuota: ";
			cin >> x1 >> x2;

			if (mappa[x1][x2] == 'X' || mappa[x1][x2] == '0')
			{
				cout << "\n\aHai inseirito le coordinate di una casella gia' occupata! Inserisci delle nuove coordinate!\n";
				goto errore;
			}

			if (x1<1 || x1>3 || x2<1 || x2>3 || x1=='#' || x2=='#')
			{
				cout << "\n\aHai inserito le coordinarte di una casella inesistente o non modificabile! Inserisci delle nuove coordinate!\n";
				break;
			}
			else
				mappa[x1][x2] = 'X';
		}
		else
		{
			cout << "\nNon ha vinto nessuno dei due giocatori!!!\n";
			break; //se la tabella è piena esce dal ciclo
		}

	} while (x1 < 1 || x1>3 || x2 < 1 || x2>3 || x1 == '#' || x2 == '#');

	StampaMappa();
}

void AggiornaGiocatore2(char mappa[][5])
{
	int x1, x2, c = 0;

	do
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
			{
				if (mappa[i][j] == ' ')
					c++;
			}

		if (c != 0) //mappa non completa
		{
		errore: //flag goto
			cout << "\nInserisci le coordinate x e y di una casella vuota: ";
			cin >> x1 >> x2;

			if (mappa[x1][x2] == 'X' || mappa[x1][x2] == '0')
			{
				cout << "\n\aHai inseirito le coordinate di una casella gia' occupata! Inserisci delle nuove coordinate!\n";
				goto errore;
			}

			if (x1 < 1 || x1>3 || x2 < 1 || x2>3 || x1 == '#' || x2 == '#')
			{
				cout << "\n\aHai inserito le coordinarte di una casella inesistente o non modificabile! Inserisci delle nuove coordinate!\n";
				break;
			}
			else
				mappa[x1][x2] = '0';
		}
		else
		{
			cout << "\nNon ha vinto nessuno dei due giocatori!!!\n";
			break; //se la tabella è piena esce dal ciclo
		}

	} while (x1 < 1 || x1>3 || x2 < 1 || x2>3 || x1 == '#' || x2 == '#');

	StampaMappa();
}

void AggiornaComputer(char mappa[][5])
{
generanumeri:
	srand(time(NULL));
	int x1 = (rand() % 2) + 1; //genera un numero da 1 a 3
	int x2 = (rand() % 2) + 1; //genera un numero da 1 a 3
	int c = 0;

	do
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
				if (mappa[i][j] == ' ')
					c++;

		if (c != 0)
		{
			if (mappa[x1][x2] == 'X' || mappa[x1][x2] == '0')
				goto generanumeri;
			if (x1 < 1 || x1>3 || x2 < 1 || x2>3 || x1 == '#' || x2 == '#')
				break;
			else
				mappa[x1][x2] = '0';
		}
		else
			break;
	} while (x1 < 1 || x1>3 || x2 < 1 || x2>3 || x1 == '#' || x2 == '#');

	StampaMappa();
}

int Vittoria(char mappa[][5]) //torna 1 se vince il giocatore, 2 se vince il pc, 0 se il gioco non è finito
{	//casisitche giocatore1			//riga1														//riga2																	//riga3																		//colonna1													//colonna2															//colonna3																	//diag1															//diag2
	if ((mappa[1][1] == 'X' && mappa[1][2] == 'X' && mappa[1][3] == 'X') || (mappa[2][1] == 'X' && mappa[2][2] == 'X' && mappa[2][3] == 'X') || (mappa[3][1] == 'X' && mappa[3][2] == 'X' && mappa[3][3] == 'X') || (mappa[1][1] == 'X' && mappa[2][1] == 'X' && mappa[3][1] == 'X') || (mappa[1][2] == 'X' && mappa[2][2] == 'X' && mappa[3][2] == 'X') || (mappa[1][3] == 'X' && mappa[2][3] == 'X' && mappa[3][3] == 'X') || (mappa[1][1] == 'X' && mappa[2][2] == 'X' && mappa[3][3] == 'X') || (mappa[1][3] == 'X' && mappa[2][2] == 'X' && mappa[3][1] == 'X'))
		return 1;	//casistiche computer //riga1													//riga2																	//riga3																		//colonna1													//colonna2															//colonna3																	//diag1															//diag2
	else if ((mappa[1][1] == '0' && mappa[1][2] == '0' && mappa[1][3] == '0') || (mappa[2][1] == '0' && mappa[2][2] == '0' && mappa[2][3] == '0') || (mappa[3][1] == '0' && mappa[3][2] == '0' && mappa[3][3] == '0') || (mappa[1][1] == '0' && mappa[2][1] == '0' && mappa[3][1] == '0') || (mappa[1][2] == '0' && mappa[2][2] == '0' && mappa[3][2] == '0') || (mappa[1][3] == '0' && mappa[2][3] == '0' && mappa[3][3] == '0') || (mappa[1][1] == '0' && mappa[2][2] == '0' && mappa[3][3] == '0') || (mappa[1][3] == '0' && mappa[2][2] == '0' && mappa[3][1] == '0'))
		return 2;
	else
		return 0;
}

bool MappaCompleta(char mappa[][5])
{
	int c = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (mappa[i][j] == ' ')
				c++;

	if (c == 0) //mappa al completo
		return true;
	else
		return false;
}

void PulisciMappa(char mappa[][5])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
		{
			mappa[i][j] = ' ';
		}
}

int main()
{
	int x, y, z;

inizio:
	system("cls");

	cout << "\nSi vuole giocare contro il computer inserisci 0 altrimenti se si desidera giocare contro un'altra persona inserisci qualsiasi altro numero: ";
	cin >> z;

	if (z == 0)
	{
		cout << "\nInserire 0 se il giocatore vuole iniziare per primo altrimenti inserire un qualsiasi altro numero: ";
		cin >> y;

		if (y == 0)
			while (Vittoria(mappa) == 0 && MappaCompleta(mappa) == false) //gioco non terminato
			{
				cout << "\nE' il tuo turno!\n";
				AggiornaGiocatore1(mappa);

				AggiornaComputer(mappa);
			}
		else
			while (Vittoria(mappa) == 0 && MappaCompleta(mappa) == false) //gioco non terminato
			{
				AggiornaComputer(mappa);

				cout << "\nE' il tuo turno!\n";
				AggiornaGiocatore1(mappa);
			}
	}

	system("cls");

	//partita finita
	if (Vittoria(mappa) == 1)
		cout << "\n\aHa vinto il giocatore!\n";
	else if (Vittoria(mappa) == 2)
		cout << "\n\aHa vinto il computer, sarai piu' fortunato!\n";

	if (MappaCompleta(mappa) == true)
		cout << "\nNon ha vinto nessuno dei due\n";

	cout << "\nSi vuole giocare ancora? (Se si inserire 0) ";
	cin >> x;

	if (x == 0)
	{
		PulisciMappa(mappa);
		goto inizio;
	}
	else
		cout << "\n\aGrazie per aver giocato al mio gioco!";

	return 0;
}