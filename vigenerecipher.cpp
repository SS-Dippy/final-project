#include <iostream>
#include <string>

using namespace std; 

/* NEEDS LOOP FOR KEY TO MATCH PLAIN TEXT*/
/* NEEDS LOOP FOR ECRIPTION*/
/* NEEDS MAIN OUT PRACTICE*/
/**/
/*****************************************************
************INCREASING LENGTH OF JEY******************
******************************************************/
string keyLenght(string txt, string ke)
{
	/* asks to see whether the key is bigger
	than the size of the plain text*/
	if (ke.size() >= txt.size())
		return ke;
	else {
		/* converts variables so that it can change */
		int textsize = txt.size() - ke.size();

		int keysize = ke.size();
		/* adds the key upon itself so that 
		it can be longer than the plain text*/
		while (textsize >= keysize)
		{
			ke += ke;
			textsize -= keysize;
		}
		ke += ke.substr(0, keysize);
		return ke;
	}
}

/*****************************************************
*********************ENCRYPTION***********************
******************************************************/
string encription(string txt, string ke)
{
	string cipher = "";
	/*it brings uses(row + colum) mod 26,
	with cipher being the colum and txt being the
	row*/
	for (int i = 0; i < txt.size(); i++)
		cipher += (char) (((int)txt[i] - 'A' + (int)ke[i] - 'A') % 26) + 'A' ;
	return cipher;
}

/*****************************************************
**********************DECRYPTION**********************
******************************************************/
string unencription(string cipher, string ke)
{
	string txt = "";
	/*brings upon the inverse of the encription by increasing */
	for (int i = 0; i < cipher.size(); i++)
		txt += (char)((((int)cipher[i] - 'A' - 
		(ke[i] - 'A')) + 26) % 26) + 'A';

	return txt;
}
/*****************************************************
*************************MAIN*************************
******************************************************/
int main()
{
	string text = "HELLOWORLD";
	string key = "KING";

	key = keyLenght(text, key);

	cout << " your text: " << text << endl << " key: " << key << endl;

	string encripttxt = encription(text, key);

	cout << " encripted text: " << encripttxt << endl;

	text = unencription(encripttxt, key);
	cout << " decripted text: " << text;
	return 0;
}