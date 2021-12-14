package sort;

public class Item implements Comparable{

	private int value;
	public Item() {
	}
	public Item(int v) {
		value = v;
	}
	public int getValue() {
		return value;
	}
	public void setValue(int v) {
		value = v;
	}
	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		Item x = (Item)o;
		if( value < x.value ) return -1;
		else if(value == x.value) return 0;
		else return 1;
	}
	@Override
	public String toString() {
		return String.valueOf(value)   ;
	}

}
