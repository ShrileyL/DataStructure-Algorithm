public class MyFirstJavaProgram
{
	//static variable
	static double PI = 3.1415926;
	static int id;
	public static void method1()
	{
		id = 10;
	}

	//method
	public void fun()
	{
		int id;
		id = 3;
		System.out.println(id);
		//method1();
		System.out.println(MyFirstJavaProgram.id);
		System.out.println(MyFirstJavaProgram.PI);
	}

	//constructor
	public MyFirstJavaProgram(){
		System.out.println("constructor");
	}

	public static void main(String[] args) {
		System.out.println("Hello Java");	
		MyFirstJavaProgram obj = new MyFirstJavaProgram();
		method1();
		obj.fun();
		for (int i=0; i < args.length ;i++ ) {
			System.out.println(args[i]);
		}
	}
}