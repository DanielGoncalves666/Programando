use std::io;

fn main() {
	let mut a = String::new();
	let mut b = String::new();
	let mut c = String::new();
	let mut d = String::new();

	io::stdin()
		.read_line(&mut a)
		.expect("Falha 1");
	io::stdin()
		.read_line(&mut b)
		.expect("Falha 2");
	io::stdin()
		.read_line(&mut c)
		.expect("Falha 3");
	io::stdin()
		.read_line(&mut d)
		.expect("Falha 4");

	let a: i32 = a.trim().parse().expect("Falha 5");	
	let b: i32 = b.trim().parse().expect("Falha 6");	
	let c: i32 = c.trim().parse().expect("Falha 7");	
	let d: i32 = d.trim().parse().expect("Falha 8");	

	let diferenca = a * b - c * d;

	println!("DIFERENCA = {}",diferenca);
}