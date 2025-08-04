#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIES 3
#define PASSWORD_LENGTH 20
#define ENCRYPTION_KEY 0x4F // Simple XOR key

// Function to encrypt or decrypt a password using XOR
void xorEncryptDecrypt(char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ ENCRYPTION_KEY;
    }
}

// Function to compare user input password with encrypted stored password
int verifyPassword(const char *input, const char *encryptedStored) {
    char decrypted[PASSWORD_LENGTH] = {0};
    xorEncryptDecrypt((char *)encryptedStored, decrypted);
    return strcmp(input, decrypted) == 0;
}

int main() {
    char storedPasswordEncrypted[PASSWORD_LENGTH];
    char inputPassword[PASSWORD_LENGTH];
    int balance = 100000, option, deposit, withdrawal;

    // Store encrypted password in memory
    char realPassword[] = "2437";
    xorEncryptDecrypt(realPassword, storedPasswordEncrypted);

    // Allow up to 3 attempts
    int attempts = MAX_TRIES;
    while (attempts--) {
        printf("Enter your 4-digit ATM password: ");
        scanf("%s", inputPassword);

        if (verifyPassword(inputPassword, storedPasswordEncrypted)) {
            printf("\n✅ Access Granted\n");
            break;
        } else {
            printf("❌ Incorrect Password. Attempts left: %d\n", attempts);
            if (attempts == 0) {
                printf("🚫 Card blocked due to multiple failed attempts.\n");
                return 0;
            }
        }
    }

    // Transaction Loop
    while (1) {
        printf("\n=========== ATM MAIN MENU ===========\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("=====================================\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter amount to deposit: ₹");
                scanf("%d", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("✅ ₹%d deposited successfully.\n", deposit);
                } else {
                    printf("❌ Invalid amount!\n");
                }
                break;

            case 2:
                printf("Enter amount to withdraw: ₹");
                scanf("%d", &withdrawal);
                if (withdrawal <= 0 || withdrawal > balance) {
                    printf("❌ Transaction failed. Invalid amount or insufficient balance.\n");
                } else {
                    balance -= withdrawal;
                    printf("✅ ₹%d withdrawn successfully.\n", withdrawal);
                }
                break;

            case 3:
                printf("📊 Current Balance: ₹%d\n", balance);
                break;

            case 4:
                printf("🛑 Exiting. Please collect your card.\n");
                printf("********* THANK YOU, VISIT AGAIN *********\n");
                exit(0);

            default:
                printf("⚠️ Invalid Option. Try again.\n");
        }
    }

    return 0;
}
