class Meat
{
	System.out.println("��");
}
class Fruit
{
	System.out.println("ˮ��");
}
class Vegetables
{
	System.out.println("�߲�");
}
public class OderDishes implements ChooseWay
{
	public String food;
	public void calWaiter(String food)
	{
		System.out.println("���з���Ա���,meat/fruit/vegetables");
		this.food = food;	
	}
	public void choosComputer(String food)
	{
		System.out.println("ʹ��ƽ����Ե��,meat/fruit/vegetables");
		this.food = food;
	}
		
}