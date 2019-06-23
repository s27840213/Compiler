
int test(int a,int b){
    return a+b;
}

void main(){
    int a = 1;
    int c = 5;

    if(a>0){
        a = 10;
        print("a>0");
    }
    else if (a<0){
        print("a<0");
    }
    else{
        print("a=0");
    }
    a*=5;
    print(a);
    return;
}

