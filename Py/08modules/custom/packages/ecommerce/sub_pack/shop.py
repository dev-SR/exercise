# from ecommerce.intra_pack_ref import shop_details  # absolute import
from ..intra_pack_ref import shop_details  # relative import


def shopping():
    print(shop_details.ShoppingDetails())
