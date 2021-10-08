/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:01:26 by hmorales          #+#    #+#             */
/*   Updated: 2021/10/04 18:45:36 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *spm;
	char uno_dos1[4] = {'4','2','1','3'};
	char uno_dos2[4] = {'4','1','2','3'};
	char uno_dos[2][4];
	char uno_tres1[4] = {'4','3','1','2'};
	char uno_tres2[4] = {'4','1','3','2'};
	char uno_tres3[4] = {'4','2','3','1'};
	char uno_tres[3][4];
	char dos_uno1[4] = {'3','2','1','4'};
	char dos_uno2[4] = {'3','1','2','4'};
	char dos_uno[2][4];
	char dos_dos1[4] = {'3','4','1','2'};
	char dos_dos2[4] = {'2','4','1','3'};
	char dos_dos3[4] = {'2','1','4','3'};
	char dos_dos4[4] = {'3','1','4','2'};
	char dos_dos5[4] = {'1','4','2','3'};
	char dos_dos6[4] = {'3','2','4','1'};
	char dos_dos[6][4];
	char dos_tres1[4] = {'3','4','2','1'};
	char dos_tres2[4] = {'2','4','3','1'};
	char dos_tres3[4] = {'1','4','3','2'};
	char dos_tres[3][4];
	char tres_uno1[4] = {'2','1','3','4'};
	char tres_uno2[4] = {'2','3','1','4'};
	char tres_uno3[4] = {'1','3','2','4'};
	char tres_uno[3][4];
	char tres_dos1[4] = {'1','2','4','3'};
	char tres_dos2[4] = {'1','3','4','2'};
	char tres_dos3[4] = {'2','3','4','1'};
	char tres_dos[3][4];
	char colup[4];
	char coldown[4];
	char rowleft[4];
	char rowright[4];
	char aux[5][5];
	char matrix[5][5];
	int i;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;

	//intento de reduccion de variables
	i = 0;
	a = 0;
	while (i < 4)
	{
		uno_dos[0][i] = uno_dos1[i];
		uno_dos[1][i] = uno_dos2[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		uno_tres[0][i] = uno_tres1[i];
		uno_tres[1][i] = uno_tres2[i];
		uno_tres[2][i] = uno_tres3[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		dos_uno[0][i] = dos_uno1[i];
		dos_uno[1][i] = dos_uno2[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		dos_dos[0][i] = dos_dos1[i];
		dos_dos[1][i] = dos_dos2[i];
		dos_dos[2][i] = dos_dos3[i];
		dos_dos[3][i] = dos_dos4[i];
		dos_dos[4][i] = dos_dos5[i];
		dos_dos[5][i] = dos_dos6[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		dos_tres[0][i] = dos_tres1[i];
		dos_tres[1][i] = dos_tres2[i];
		dos_tres[2][i] = dos_tres3[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tres_uno[0][i] = tres_uno1[i];
		tres_uno[1][i] = tres_uno2[i];
		tres_uno[2][i] = tres_uno3[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tres_dos[0][i] = tres_dos1[i];
		tres_dos[1][i] = tres_dos2[i];
		tres_dos[2][i] = tres_dos3[i];
		i++;
	}
	i = 0;
	//introduccion de datos
	argc = 1;
	spm = argv[1];
	//spm = "4321 1222 4321 1222";
	//organizacion de informacion
	i = 0;
	while (spm[i] != '\0')
	{
		if ((spm[i] < '1' || spm[i] > '4') && spm[i] != ' ')
		{
			write(1, "ERROR: Non-computable inputs", 28);
			return(0);
		}
		else if ((spm[i] >= '1' && spm[i] <= '4') && a < 4)
		{
			colup[a] = spm[i];
			a++;
		}
		else if ((spm[i] >= '1' && spm[i] <= '4') && (a >= 4 && a < 8))
		{
			coldown[a - 4] = spm[i];
			a++;
		}
		else if ((spm[i] >= '1' && spm[i] <= '4') && (a >= 8 && a < 12))
		{
			rowleft[a - 8] = spm[i];
			a++;
		}
		else if ((spm[i] >= '1' && spm[i] <= '4') && (a >= 12 && a < 16))
		{
			rowright[a - 12] = spm[i];
			a++;
		}
		i++;
	}
	a = 0;
	//funcion de control de combionaciones
	//esquinas
	if ((rowleft[0] == '1' && colup[0] != '1') || (rowleft[0] != '1' && colup[0] == '1'))
		a = 1;
	if ((rowleft[3] == '1' && coldown[0] != '1') || (rowleft[3] != '1' && coldown[0] == '1'))
		a = 1;
	if ((rowright[3] == '1' && coldown[3] != '1') || (rowright[3] != '1' && coldown[3] == '1'))
		a = 1;
	if((rowright[0] == '1' && colup[3] != '1') || (rowright[0] != '1' && colup[3] == '1'))
		a = 1;
	//paralelos (izda/dcha)
	i = 0;
	while (i < 4)
	{
		if (rowleft[i] == '1' && rowright[i] == '1')
			a = 1;
		else if ((rowleft[i] == '2' && rowright[i] == '4') || (rowleft[i] == '4' && rowright[i] == '2'))
			a = 1;
		else if ((rowleft[i] == '3' && rowright[i] == '4') || (rowleft[i] == '4' && rowright[i] == '3'))
			a = 1;
		else if (rowleft[i] == '3' && rowright[i] == '3')
			a = 1;
		else if (rowleft[i] == '4' && rowright[i] == '4')
			a = 1;
		i ++;
	}
	//paralelos (arriba/abajo)
	i = 0;
	while (i < 4)
	{
		if (colup[i] == '1' && coldown[i] == '1')
			a = 1;
		else if ((colup[i] == '2' && coldown[i] == '4') || (colup[i] == '4' && coldown[i] == '2'))
			a = 1;
		else if ((colup[i] == '3' && coldown[i] == '4') || (colup[i] == '4' && coldown[i] == '3'))
			a = 1;
		else if (colup[i] == '3' && coldown[i] == '3')
			a = 1;
		else if (colup[i] == '4' && coldown[i] == '4')
			a = 1;
		i ++;
	}
	//comprobador de error de input
	if (a == 1)
	{
		write(1, "ERROR: Non-computable inputs", 28);
		return(0);
	}
	
	//incializador de matriz
	i = 0;
	a = 0;
	while (i < 5)
	{
		while (a < 5)
		{
			matrix[i][a] = '8';
			aux[i][a] = '8';
			a++;
		}
		a = 0;
		i++;
	}
	//algoritmo "CONICIONAL"
	i = 0;
	a = 0;
	while (i < 4)
	{
		a = 0;
		if(colup[i] == '4')	
		{
			while (a < 4)
			{
				matrix[a][i] = '1' + a;
				a++;
			}
		}
		else if (colup[i] == '1')
		{
			matrix[0][i] = '1';
		}
		//	
		a = 0;
		if (coldown[i] == '4')
		{
			while(a < 4)
			{
				matrix[a][i]= '4' - a;
				a++;
			}
		}
		else if (coldown[i] == '1')
		{
			matrix[3][i] = '1';
		}
		//		
		a = 0;
		if (rowleft[i] == '4')
		{	
			while(a < 4)
			{
				matrix[i][a]= '1' + a;
				a++;
			}
		}
		else if (rowleft[i] == '1')
		{
			matrix[i][0] = '1';
		}		
		//
		a = 0;
		if (rowright[i] == '4')
		{	
			while(a < 4)
			{
				matrix[i][a]= '4' - a;
				a++;
			}
		}
		else if (rowright[i] == '1')
			matrix[i][3] = '1';
		//
		a = 0;
		if (colup[i] == '1' && coldown[i] == '2')
		{
			matrix[0][i] = '4';
			matrix[3][i] = '3';
		}
		else if (colup[i] == '2' && coldown[i] == '1')
		{
			matrix[0][i] = '3';
			matrix[3][i] = '4';
		}
		//
		if (rowleft[i] == '1' && rowright[i] == '2')
		{
			matrix[i][0] = '4';
			matrix[i][3] = '3';
		}
		else if (rowright[i] == '2' && rowleft[i] == '1')
		{
			matrix[i][0] = '3';
			matrix[i][3] = '4';
		}
		//
		if (colup[i] == '2' && coldown[i] == '3')
		{
			matrix[1][i] = '4';
		}	
		else if (colup[i] == '3' && coldown[i] == '2')
		{
			matrix[2][i] = '4';
		}
		//
		if (rowright[i] == '3' && rowleft[i] == '2')
		{
			matrix[i][1] = '4';
		}
		else if(rowright[i] == '2' && rowleft[i] == '3')
		{
			matrix[i][2] = '4';
		}
		i++;
	}
	//algoritmo "COPIA"
	i = 0;
	a = 0;
	while (i < 4)
	{
		while (a < 4)
		{
			aux[i][a] = matrix[i][a];
			a++;
		}
		a = 0;
		i++;
	}
	//printeo
	i = 0;
	a = 0;
	while (i < 4)
	{
		while (a < 4)
		{
			write(1, &matrix[i][a], 1);
			write(1, " ", 1);
			a++;
		}
		write(1, "\n", 1);
		a = 0;
		i++;
	}
	//algoritmo "LA BESTIA"
	i = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	while (i < 4)
	{
		if (colup[i] == '1' && coldown[i] == '2')
		{
			while (a < 4 && b < 2)
			{
				if(uno_dos[b][a] != matrix[a][i] && matrix[a][i] != '8')
				{
					b++;
					a = 0;
				}
				a++;
			}
			a = 0;
			while (a < 4)
			{
				if(b < 2)
				{
					aux[a][i] = uno_dos[b][a];
					while (c < 4)
					{
						while (d < 3)
						{
							while (e < 4)
							{
								if (aux[c][d] == matrix[c][e])
								{
									b++;
									a = 0;
									while (f < 4)
									{
										while (g < 4)
										{
											aux[f][g] = matrix[f][g];
											g++;
										}
										f++;
										g = 0;
									}
								}
								e++;
							}
							d++;
							e = d + 1;
						}
						c++;
					}
					a++;
				}
				else
					a = 4;
			}
			a = 0;
		}
		i++;
	}
//---------------------------------------------------------------------	
	i = 0;
	a = 0;
	while (i < 4)
	{
		while (a < 4)
		{
			matrix[i][a] = aux[i][a];
			a++;
		}
		a = 0;
		i++;
	}
//-------------------------------------------
	i = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	while (i < 4)
	{
		if (colup[i] == '3' && coldown[i] == '2')
		{
			while (a < 4 && b < 3)
			{
				if(tres_dos[b][a] != matrix[a][i] && matrix[a][i] != '8')
				{
					b++;
					a = 0;
				}
				a++;
			}
			a = 0;
			while (a < 4)
			{
				if(b < 3)
				{
					aux[a][i] = tres_dos[b][a];
					while (c < 4)
					{
						while (d < 3)
						{
							while (e < 4)
							{
								if (aux[c][d] == matrix[c][e])
								{
									b++;
									a = 0;
									while (f < 4)
									{
										while (g < 4)
										{
											aux[f][g] = matrix[f][g];
											g++;
										}
										f++;
										g = 0;
									}
								}
								e++;
							}
							d++;
							e = d + 1;
						}
						c++;
					}
					a++;
				}
				else
					a = 4;
			}
			a = 0;
		}
		i++;
	}
//-----------------------------------------------
	i = 0;
	a = 0;
	while (i < 4)
	{
		while (a < 4)
		{
			matrix[i][a] = aux[i][a];
			a++;
		}
		a = 0;
		i++;
	}
//-------------------------------------------
	i = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	while (i < 4)
	{
		if (colup[i] == '2' && coldown[i] == '2')
		{
			while (a < 4 && b < 6)
			{
				if(dos_dos[b][a] != matrix[a][i] && matrix[a][i] != '8')
				{
					b++;
					a = 0;
				}
				a++;
			}
			a = 0;
			while (a < 4)
			{
				if(b < 6)
				{
					aux[a][i] = dos_dos[b][a];
					while (c < 4)
					{
						while (d < 3)
						{
							while (e < 4)
							{
								if (aux[c][d] == matrix[c][e])
								{
									b++;
									a = 0;
									while (f < 4)
									{
										while (g < 4)
										{
											aux[f][g] = matrix[f][g];
											g++;
										}
										f++;
										g = 0;
									}
								}
								e++;
							}
							d++;
							e = d + 1;
						}
						c++;
					}
					a++;
				}
				else
					a = 4;
			}
			a = 0;
		}
		i++;
	}
	//printeo de matrix
	write(1, "\n", 1);
	i = 0;
	a = 0;
	while (i < 4)
	{
		while (a < 4)
		{
			write(1, &aux[i][a], 1);
			write(1, " ", 1);
			a++;
		}
		write(1, "\n", 1);
		a = 0;
		i++;
	}
}
