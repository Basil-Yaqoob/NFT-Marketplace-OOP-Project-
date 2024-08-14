#include"NFT_Marketplace.h"
int main() {
	welcomepage();
	char a;
	int choice, c1, c2, c3;
	User u1;
	Ewallet e1;

	Seller s1;
	NFT nft;

	while (1) {
		cout << "How do you want to Enter\n(1)Admin\n(2)User\n(3)End\n";
		cin >> choice;
		//start switch 1
		switch (choice) {
			//start case 1:switch 1
		case 1: {
			Person* ptr;
			ptr = new Admin;
			int n = 3;
			string u, pass;
			bool authenticate = false;
			while (n >= 1) {
				cout << "Total Attempts Remaining :" << n << endl;
				cout << "Enter Username: \n";
				cin >> ws;
				getline(cin, u);
				cout << "Enter Password: \n";
				getline(cin, pass);
				if (ptr->getUsername() == u && ptr->getPassword() == pass) {
					authenticate = true;
					cout << "Login Successfull\n";
					break;
				}
				else {
					n--;
					cout << "Login Unsuccessfull!\nTry Again\n";
				}

			}
			if (authenticate) {
				while (1) {
					cout << "\nWhat do you want to do:\n(1)Print Your Details\n(2)View All NFTs\n(3)Delete NFT\n(4)Update NFT Details\n(5)Modify User Details\n(6)Delete User Details\n(7)View Current Conversion Rate\n(8)Get Nft Winner\n(9)End\n\n";
					cin >> c3;
					switch (c3) {
					case 1: {
						ptr->display();
						break;
					}
					case 2: {
						nft.viewallNFT();
						break;
					}
					case 3: {
						string u;
						cout << "Enter The Name of Nft You want to Delete: ";
						cin >> ws;
						getline(cin, u);
						nft.deleteNft(u);
						break;
					}
					case 4: {
						string n, name, on, d, user;
						int price = 0;
						cout << "WHICH NFT YOU WANT TO UPDATE :";
						cin >> ws;
						getline(cin, n);
						cout << "ENTER THE NAME OF NFT :";
						getline(cin, name);
						cout << "ENTER OWNER NAME : ";
						getline(cin, on);
						cout << "ENTER DESCRIPTION :";
						getline(cin, d);
						cout << "ENTER USERNAME :";
						getline(cin, user);
						cout << "ENTER PRICE : ";
						cin >> ws;
						cin >> price;
						nft.updateNft(n, name, on, d, price, user);
						break;
					}
					case 5: {
						string address, user, pass, contact, u;
						int age;

						while (getchar() != '\n');
						cout << "Enter The Name of User you Want to Update: \n";
						getline(cin, u);

						cout << "\t\t\t\t\t\t\tEnter Age: ";
						cin >> age;
						while (getchar() != '\n');
						cout << "\t\t\t\t\t\t\tEnter Contact Number: ";
						getline(cin, contact);

						cout << "\t\t\t\t\t\t\tEnter Address: ";
						getline(cin, address);
						cout << "\t\t\t\t\t\t\tEnter Username: ";
						getline(cin, user);
						cout << "\t\t\t\t\t\t\tEnter Password: ";
						getline(cin, pass);
						u1.update_user(u, age, contact, address, user, pass);
						break;
					}
					case 6: {
						string u;
						cout << "Enter Which User you want to Delete: \n";
						cin >> ws;
						getline(cin, u);
						u1.delete_user(u);
						break;

					}
					case 7: {
						cout << "The Current Conversion Rate for 1 USD is : " << e1.findCurrentConversionRate() << endl;
						break;
					}
					case 8: {
						string t;
						cout << "Enter The Name of NFT whose Winner you Want to Find: ";
						cin >> ws;
						getline(cin, t);
						nft.getwinner(t);
						break;
					}
					case 9: {
						return 0;
					}
					default: {
						cout << "Invalid Input Try Again";
					}
					}
				}
			}

			break;

		}//end case 1:switch 1
			//start case 2:switch 1
		case 2: {

			cout << "Do you want to \n(1)Login\n(2)Signup\n";
			cin >> c1;
			//start switch 2	
			switch (c1) {
				//start case 1:switch 2
			case 1: {
			h1:
				string user, pass;
				int n = 3;
				bool authenticate = false;

				while (n >= 1) {
					cout << "\t\t\t\t\t\t\t Total Attempts Remaining :" << n << endl;
					cout << "\t\t\t\t\t\t\tEnter Username: ";
					cin >> ws;
					getline(cin, user);
					cout << "\t\t\t\t\t\t\tEnter Password: ";
					getline(cin, pass);
					if (u1.login(user, pass)) {
						cout << "\t\t\t\t\t\t\tLogin Sucessfull\n";
						authenticate = true;
						n = 0;
					}
					else {
						cout << "\t\t\t\t\t\t\tLogin Unsucessfull Try Again\n";
						n--;
					}
				}
				if (authenticate) {
					//work here
					while (1) {
					h2:
						cout << "What Do You want to Do:\n(1)Buy NFT\n(2)Sell NFT\n(3)View All NFTs\n(4)Enter Your Ewallet\n(5)View Your NFTs\n(6)Update Nft\n(7)Delete Nft\n(8)End\n";
						cin >> choice;
						switch (choice) {
						case 1: {
							string a;
							cout << "Enter The Name Of Nft you want to buy :";
							cin >> ws;
							getline(cin, a);
							NftAuction nfta1(a, 1000);
							nfta1.addBid(u1);
							goto h2;
							break;
						}//buy nft;
						case 2: {
							s1.SellNFT(u1);
							break;
						}//sell nft
						case 3: {
							nft.viewallNFT();
							break;
						}
						case 4: {
						here:
							cout << "What do you Want to do:\n(1)View Ewallet\n(2)Convert USD into Crypto Coins\n(3)Convert Crypto Coins into USD\n(4)Modify Ewallet\n(5)Delete your Ewallet\n(6)View Conversion Rate\n";
							cin >> c2;
							switch (c2) {
							case 1: {
								e1.displayEwallet(u1);
								cout << "Press Enter To Continue\n";

								break;
							}
							case 2: {
								double amount;
								cout << "Enter Amount to Convert:";
								cin >> amount;
								e1.usd_into_crypto(u1, amount);

								break;
							}
							case 3: {
								double amount;
								cout << "Enter Amount to Convert:";
								cin >> amount;
								e1.crypto_into_usd(u1, amount);

								break;
							}
							case 4: {
								string u, c;
								double usd;
								//u = u1.getUsername();
								cout << "Enter Your New Credit Card Number: ";
								cin >> ws;
								getline(cin, c);
								cout << "Enter Your Balance in USD: ";
								cin >> usd;
								e1.update_ewallet(u1, c, usd);
								break;
							}//modify Ewallet
							case 5: {
								e1.delete_Ewallet("bas");

								break;
							}//Delete Ewallet
							case 6: {
								double a = e1.findCurrentConversionRate();
								cout << a << endl;
								break;
							}
							default: {
								cout << "Invalid Input";
							}
								   goto here;
							}
							break;
						}//Ewallet
						case 5: {
							nft.displayNFT(u1);
							break;
						}
						case 6: {
							string n, name, on, d, user;
							int price = 0;
							cout << "WHICH NFT YOU WANT TO UPDATE :";
							cin >> ws;
							getline(cin, n);
							cout << "ENTER THE NAME OF NFT :";
							getline(cin, name);
							cout << "ENTER OWNER NAME : ";
							getline(cin, on);
							cout << "ENTER DESCRIPTION :";
							getline(cin, d);
							cout << "ENTER USERNAME :";
							getline(cin, user);
							cout << "ENTER PRICE : ";
							cin >> ws;
							cin >> price;

							nft.updateNft(n, name, on, d, price, user);
							break;
						}
						case 7: {
							string n;
							cout << "Enter The name of NFT you want to Delete: ";
							cin >> ws;
							getline(cin, n);
							nft.deleteNft(n);
						}
						case 8: {
							return 0;
						}
							  break;
						default: {
							cout << "Invalid Input";
						}
						}
					}
				}
				break;
			}//end case 1:switch 2
				  //start case 2:switch 2
			case 2: {
				string name, address, user, pass, nic, contact, crd_card_no;
				double dollar;
				int age;

				while (getchar() != '\n');
				cout << "\t\t\t\t\t\t\tEnter Name: ";
				getline(cin, name);
				cout << "\t\t\t\t\t\t\tEnter Age: ";
				cin >> age;
				while (getchar() != '\n');
				cout << "\t\t\t\t\t\t\tEnter Contact Number: ";
				getline(cin, contact);
				cout << "\t\t\t\t\t\t\tEnter Nic Number: ";
				getline(cin, nic);
				cout << "\t\t\t\t\t\t\tEnter Address: ";
				getline(cin, address);
				cout << "\t\t\t\t\t\t\tEnter Username: ";
				getline(cin, user);
				cout << "\t\t\t\t\t\t\tEnter Password: ";
				getline(cin, pass);
				User u1(name, age, nic, contact, address, user, pass);
				u1.store_data();
				cout << "Press Enter To Continue\n";
				a = getchar();
				system("cls");
				cout << "\t\t\t\t\t\t************ Creating Ewallet ************\n";
				cout << "\t\t\t\t\t\t\tEnter Credit Card Number To Create your Ewallet: ";
				getline(cin, crd_card_no);
				cout << "\t\t\t\t\t\t\tEnter Your Balance in Usd: ";
				cin >> dollar;
				Ewallet e1(u1.getUsername(), crd_card_no, dollar);
				e1.storeEwallet();
				goto h1;
				break;
			}//end case 2:switch 2
			default: {
				cout << "Invalid Input! \n";

			}
			}//end switch 2
		} // end case 2:switch 1
		case 3: {
			return 0;
		}
		default: {
			cout << "Invalid Input! \n";
		}
		}//end switch 1}

	}
}