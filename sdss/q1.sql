explain analyze select star.objid, star.extinction_u, star.extinction_g, star.extinction_r, star.l, star.b from star where  star.clean = 1 and (star.l between 150.055 and 150.058) and (star.b between -12.087 and -12.085) and star.type = 6;