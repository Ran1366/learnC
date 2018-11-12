class Meat
{
	System.out.println("肉");
}
class Fruit
{
	System.out.println("水果");
}
class Vegetables
{
	System.out.println("蔬菜");
}
public class OderDishes implements ChooseWay
{
	public String food;
	public void calWaiter(String food)
	{
		System.out.println("呼叫服务员点菜,meat/fruit/vegetables");
		this.food = food;	
	}
	public void choosComputer(String food)
	{
		System.out.println("使用平板电脑点菜,meat/fruit/vegetables");
		this.food = food;
	}
		
}