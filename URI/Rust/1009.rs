use std::io;

fn main() {
	let mut nome = String::new();
	let mut salario = String::new();
	let mut vendas = String::new();

	io::stdin()
		.read_line(&mut nome)
		.expect("Falha 1");
	io::stdin()
		.read_line(&mut salario)
		.expect("Falha 2");
	io::stdin()
		.read_line(&mut vendas)
		.expect("Falha 3");
	
	let salario: f64 = salario.trim().parse().expect("Falha 5");
	let vendas : f64 = vendas.trim().parse().expect("Falha 6");

	let total = salario + vendas * 0.15;

	println!("TOTAL = R$ {:.2}",total);
}