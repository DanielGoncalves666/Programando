use std::io;

fn main() {
	let handle = io::stdin();
	let mut tempo = String::new();
	let mut velocidade = String::new();

	handle.read_line(&mut tempo).expect("Falha 1");
	handle.read_line(&mut velocidade).expect("Falha 2");

	let tempo: i32 = tempo.trim().parse().expect("Falha 3");
	let velocidade: i32 = velocidade.trim().parse().expect("Falha 4");

	let distancia = tempo * velocidade;
	let litros: f64 = distancia as f64 / 12.0;

	println!("{:.3}",litros);
}