# import ecommerce.sales
# from ecommerce.sales import calc_tax
from ecommerce import sales
from ecommerce.sub_pack import shop

print("tax: "+str(sales.calc_tax(200)))
shop.shopping()
