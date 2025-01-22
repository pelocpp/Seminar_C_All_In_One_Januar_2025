

struct Wallet
{
    int euros;
    int cents;
};

void clearWallet(struct Wallet* wallet) {}
void printWallet(struct Wallet* wallet) {}
void addEuros(struct Wallet* wallet, int wievielEuros) {}
void addCents(struct Wallet* wallet, int wievielCents) {}
void addEurosAndCents(struct Wallet* wallet, int wievielEuros, int wievielCents) {}

void test_wallet()
{
    struct Wallet myWallet = { 0, 0 };

   // myWallet.cents = 50;

    clearWallet(&myWallet);

    // C++:
    // myWallet.clearWallet();

    printWallet(&myWallet);

    addEuros(&myWallet, 5);

    printWallet(&myWallet);
}