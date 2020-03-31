import networkx as nx
import matplotlib.pyplot as plt
from networkx.drawing.nx_agraph import graphviz_layout

G = nx.DiGraph()

G.add_node("AST_NODE_PROGRAM_0x655c90")
G.add_node("AST_NODE_MODULEDECLARATION_0x655cf0")
G.add_edge("AST_NODE_PROGRAM_0x655c90", "AST_NODE_MODULEDECLARATION_0x655cf0")
G.add_node("AST_NODE_MODULELIST_0x655db0")
G.add_edge("AST_NODE_PROGRAM_0x655c90", "AST_NODE_MODULELIST_0x655db0")
G.add_node("AST_NODE_MODULELIST_0x6580f0")
G.add_edge("AST_NODE_PROGRAM_0x655c90", "AST_NODE_MODULELIST_0x6580f0")
G.add_node("AST_NODE_MODULEDECLARATION_0x655cf0")
G.add_node("AST_NODE_LEAF_0x655d50")
G.add_edge("AST_NODE_MODULEDECLARATION_0x655cf0", "AST_NODE_LEAF_0x655d50")
G.add_node("AST_NODE_MODULELIST_0x655db0")
G.add_node("AST_NODE_STATEMENT_0x655e10")
G.add_edge("AST_NODE_MODULELIST_0x655db0", "AST_NODE_STATEMENT_0x655e10")
G.add_node("AST_NODE_MODULELIST_0x6580f0")
G.add_node("AST_NODE_MODULELIST_0x658190")
G.add_edge("AST_NODE_MODULELIST_0x6580f0", "AST_NODE_MODULELIST_0x658190")
G.add_node("AST_NODE_LEAF_0x655d50")
G.add_node("AST_NODE_STATEMENT_0x655e10")
G.add_node("AST_NODE_DECLARESTMT_0x655e70")
G.add_edge("AST_NODE_STATEMENT_0x655e10", "AST_NODE_DECLARESTMT_0x655e70")
G.add_node("AST_NODE_STATEMENT_0x6562f0")
G.add_edge("AST_NODE_STATEMENT_0x655e10", "AST_NODE_STATEMENT_0x6562f0")
G.add_node("AST_NODE_MODULELIST_0x658190")
G.add_node("AST_NODE_LEAF_0x658230")
G.add_edge("AST_NODE_MODULELIST_0x658190", "AST_NODE_LEAF_0x658230")
G.add_node("AST_NODE_INPUTLIST_0x6582d0")
G.add_edge("AST_NODE_MODULELIST_0x658190", "AST_NODE_INPUTLIST_0x6582d0")
G.add_node("AST_NODE_OUTPUTLIST_0x658870")
G.add_edge("AST_NODE_MODULELIST_0x658190", "AST_NODE_OUTPUTLIST_0x658870")
G.add_node("AST_NODE_STATEMENT_0x658e10")
G.add_edge("AST_NODE_MODULELIST_0x658190", "AST_NODE_STATEMENT_0x658e10")
G.add_node("AST_NODE_DECLARESTMT_0x655e70")
G.add_node("AST_NODE_IDLIST_0x655ed0")
G.add_edge("AST_NODE_DECLARESTMT_0x655e70", "AST_NODE_IDLIST_0x655ed0")
G.add_node("AST_NODE_LEAF_0x656250")
G.add_edge("AST_NODE_DECLARESTMT_0x655e70", "AST_NODE_LEAF_0x656250")
G.add_node("AST_NODE_STATEMENT_0x6562f0")
G.add_node("AST_NODE_DECLARESTMT_0x656390")
G.add_edge("AST_NODE_STATEMENT_0x6562f0", "AST_NODE_DECLARESTMT_0x656390")
G.add_node("AST_NODE_STATEMENT_0x656610")
G.add_edge("AST_NODE_STATEMENT_0x6562f0", "AST_NODE_STATEMENT_0x656610")
G.add_node("AST_NODE_LEAF_0x658230")
G.add_node("AST_NODE_INPUTLIST_0x6582d0")
G.add_node("AST_NODE_LEAF_0x658370")
G.add_edge("AST_NODE_INPUTLIST_0x6582d0", "AST_NODE_LEAF_0x658370")
G.add_node("AST_NODE_LEAF_0x658410")
G.add_edge("AST_NODE_INPUTLIST_0x6582d0", "AST_NODE_LEAF_0x658410")
G.add_node("AST_NODE_INPUTLIST_0x6584b0")
G.add_edge("AST_NODE_INPUTLIST_0x6582d0", "AST_NODE_INPUTLIST_0x6584b0")
G.add_node("AST_NODE_OUTPUTLIST_0x658870")
G.add_node("AST_NODE_LEAF_0x658910")
G.add_edge("AST_NODE_OUTPUTLIST_0x658870", "AST_NODE_LEAF_0x658910")
G.add_node("AST_NODE_LEAF_0x6589b0")
G.add_edge("AST_NODE_OUTPUTLIST_0x658870", "AST_NODE_LEAF_0x6589b0")
G.add_node("AST_NODE_OUTPUTLIST_0x658a50")
G.add_edge("AST_NODE_OUTPUTLIST_0x658870", "AST_NODE_OUTPUTLIST_0x658a50")
G.add_node("AST_NODE_STATEMENT_0x658e10")
G.add_node("AST_NODE_DECLARESTMT_0x658eb0")
G.add_edge("AST_NODE_STATEMENT_0x658e10", "AST_NODE_DECLARESTMT_0x658eb0")
G.add_node("AST_NODE_STATEMENT_0x659130")
G.add_edge("AST_NODE_STATEMENT_0x658e10", "AST_NODE_STATEMENT_0x659130")
G.add_node("AST_NODE_IDLIST_0x655ed0")
G.add_node("AST_NODE_LEAF_0x655f30")
G.add_edge("AST_NODE_IDLIST_0x655ed0", "AST_NODE_LEAF_0x655f30")
G.add_node("AST_NODE_IDLIST_0x655fd0")
G.add_edge("AST_NODE_IDLIST_0x655ed0", "AST_NODE_IDLIST_0x655fd0")
G.add_node("AST_NODE_LEAF_0x656250")
G.add_node("AST_NODE_DECLARESTMT_0x656390")
G.add_node("AST_NODE_IDLIST_0x656430")
G.add_edge("AST_NODE_DECLARESTMT_0x656390", "AST_NODE_IDLIST_0x656430")
G.add_node("AST_NODE_LEAF_0x656570")
G.add_edge("AST_NODE_DECLARESTMT_0x656390", "AST_NODE_LEAF_0x656570")
G.add_node("AST_NODE_STATEMENT_0x656610")
G.add_node("AST_NODE_DECLARESTMT_0x6566b0")
G.add_edge("AST_NODE_STATEMENT_0x656610", "AST_NODE_DECLARESTMT_0x6566b0")
G.add_node("AST_NODE_STATEMENT_0x656930")
G.add_edge("AST_NODE_STATEMENT_0x656610", "AST_NODE_STATEMENT_0x656930")
G.add_node("AST_NODE_LEAF_0x658370")
G.add_node("AST_NODE_LEAF_0x658410")
G.add_node("AST_NODE_INPUTLIST_0x6584b0")
G.add_node("AST_NODE_LEAF_0x658550")
G.add_edge("AST_NODE_INPUTLIST_0x6584b0", "AST_NODE_LEAF_0x658550")
G.add_node("AST_NODE_LEAF_0x6585f0")
G.add_edge("AST_NODE_INPUTLIST_0x6584b0", "AST_NODE_LEAF_0x6585f0")
G.add_node("AST_NODE_INPUTLIST_0x658690")
G.add_edge("AST_NODE_INPUTLIST_0x6584b0", "AST_NODE_INPUTLIST_0x658690")
G.add_node("AST_NODE_LEAF_0x658910")
G.add_node("AST_NODE_LEAF_0x6589b0")
G.add_node("AST_NODE_OUTPUTLIST_0x658a50")
G.add_node("AST_NODE_LEAF_0x658af0")
G.add_edge("AST_NODE_OUTPUTLIST_0x658a50", "AST_NODE_LEAF_0x658af0")
G.add_node("AST_NODE_LEAF_0x658b90")
G.add_edge("AST_NODE_OUTPUTLIST_0x658a50", "AST_NODE_LEAF_0x658b90")
G.add_node("AST_NODE_OUTPUTLIST_0x658c30")
G.add_edge("AST_NODE_OUTPUTLIST_0x658a50", "AST_NODE_OUTPUTLIST_0x658c30")
G.add_node("AST_NODE_DECLARESTMT_0x658eb0")
G.add_node("AST_NODE_IDLIST_0x658f50")
G.add_edge("AST_NODE_DECLARESTMT_0x658eb0", "AST_NODE_IDLIST_0x658f50")
G.add_node("AST_NODE_LEAF_0x659090")
G.add_edge("AST_NODE_DECLARESTMT_0x658eb0", "AST_NODE_LEAF_0x659090")
G.add_node("AST_NODE_STATEMENT_0x659130")
G.add_node("AST_NODE_SIMPLESTMT_0x6591d0")
G.add_edge("AST_NODE_STATEMENT_0x659130", "AST_NODE_SIMPLESTMT_0x6591d0")
G.add_node("AST_NODE_STATEMENT_0x659db0")
G.add_edge("AST_NODE_STATEMENT_0x659130", "AST_NODE_STATEMENT_0x659db0")
G.add_node("AST_NODE_LEAF_0x655f30")
G.add_node("AST_NODE_IDLIST_0x655fd0")
G.add_node("AST_NODE_LEAF_0x656070")
G.add_edge("AST_NODE_IDLIST_0x655fd0", "AST_NODE_LEAF_0x656070")
G.add_node("AST_NODE_IDLIST_0x656110")
G.add_edge("AST_NODE_IDLIST_0x655fd0", "AST_NODE_IDLIST_0x656110")
G.add_node("AST_NODE_IDLIST_0x656430")
G.add_node("AST_NODE_LEAF_0x6564d0")
G.add_edge("AST_NODE_IDLIST_0x656430", "AST_NODE_LEAF_0x6564d0")
G.add_node("AST_NODE_LEAF_0x656570")
G.add_node("AST_NODE_DECLARESTMT_0x6566b0")
G.add_node("AST_NODE_IDLIST_0x656750")
G.add_edge("AST_NODE_DECLARESTMT_0x6566b0", "AST_NODE_IDLIST_0x656750")
G.add_node("AST_NODE_LEAF_0x656890")
G.add_edge("AST_NODE_DECLARESTMT_0x6566b0", "AST_NODE_LEAF_0x656890")
G.add_node("AST_NODE_STATEMENT_0x656930")
G.add_node("AST_NODE_DECLARESTMT_0x6569d0")
G.add_edge("AST_NODE_STATEMENT_0x656930", "AST_NODE_DECLARESTMT_0x6569d0")
G.add_node("AST_NODE_STATEMENT_0x656c50")
G.add_edge("AST_NODE_STATEMENT_0x656930", "AST_NODE_STATEMENT_0x656c50")
G.add_node("AST_NODE_LEAF_0x658550")
G.add_node("AST_NODE_LEAF_0x6585f0")
G.add_node("AST_NODE_INPUTLIST_0x658690")
G.add_node("AST_NODE_LEAF_0x658730")
G.add_edge("AST_NODE_INPUTLIST_0x658690", "AST_NODE_LEAF_0x658730")
G.add_node("AST_NODE_LEAF_0x6587d0")
G.add_edge("AST_NODE_INPUTLIST_0x658690", "AST_NODE_LEAF_0x6587d0")
G.add_node("AST_NODE_LEAF_0x658af0")
G.add_node("AST_NODE_LEAF_0x658b90")
G.add_node("AST_NODE_OUTPUTLIST_0x658c30")
G.add_node("AST_NODE_LEAF_0x658cd0")
G.add_edge("AST_NODE_OUTPUTLIST_0x658c30", "AST_NODE_LEAF_0x658cd0")
G.add_node("AST_NODE_LEAF_0x658d70")
G.add_edge("AST_NODE_OUTPUTLIST_0x658c30", "AST_NODE_LEAF_0x658d70")
G.add_node("AST_NODE_IDLIST_0x658f50")
G.add_node("AST_NODE_LEAF_0x658ff0")
G.add_edge("AST_NODE_IDLIST_0x658f50", "AST_NODE_LEAF_0x658ff0")
G.add_node("AST_NODE_LEAF_0x659090")
G.add_node("AST_NODE_SIMPLESTMT_0x6591d0")
G.add_node("AST_NODE_ASSIGN_0x659270")
G.add_edge("AST_NODE_SIMPLESTMT_0x6591d0", "AST_NODE_ASSIGN_0x659270")
G.add_node("AST_NODE_STATEMENT_0x659db0")
G.add_node("AST_NODE_SIMPLESTMT_0x659e50")
G.add_edge("AST_NODE_STATEMENT_0x659db0", "AST_NODE_SIMPLESTMT_0x659e50")
G.add_node("AST_NODE_STATEMENT_0x65aa30")
G.add_edge("AST_NODE_STATEMENT_0x659db0", "AST_NODE_STATEMENT_0x65aa30")
G.add_node("AST_NODE_LEAF_0x656070")
G.add_node("AST_NODE_IDLIST_0x656110")
G.add_node("AST_NODE_LEAF_0x6561b0")
G.add_edge("AST_NODE_IDLIST_0x656110", "AST_NODE_LEAF_0x6561b0")
G.add_node("AST_NODE_LEAF_0x6564d0")
G.add_node("AST_NODE_IDLIST_0x656750")
G.add_node("AST_NODE_LEAF_0x6567f0")
G.add_edge("AST_NODE_IDLIST_0x656750", "AST_NODE_LEAF_0x6567f0")
G.add_node("AST_NODE_LEAF_0x656890")
G.add_node("AST_NODE_DECLARESTMT_0x6569d0")
G.add_node("AST_NODE_IDLIST_0x656a70")
G.add_edge("AST_NODE_DECLARESTMT_0x6569d0", "AST_NODE_IDLIST_0x656a70")
G.add_node("AST_NODE_LEAF_0x656bb0")
G.add_edge("AST_NODE_DECLARESTMT_0x6569d0", "AST_NODE_LEAF_0x656bb0")
G.add_node("AST_NODE_STATEMENT_0x656c50")
G.add_node("AST_NODE_IO_0x656cf0")
G.add_edge("AST_NODE_STATEMENT_0x656c50", "AST_NODE_IO_0x656cf0")
G.add_node("AST_NODE_STATEMENT_0x656e30")
G.add_edge("AST_NODE_STATEMENT_0x656c50", "AST_NODE_STATEMENT_0x656e30")
G.add_node("AST_NODE_LEAF_0x658730")
G.add_node("AST_NODE_LEAF_0x6587d0")
G.add_node("AST_NODE_LEAF_0x658cd0")
G.add_node("AST_NODE_LEAF_0x658d70")
G.add_node("AST_NODE_LEAF_0x658ff0")
G.add_node("AST_NODE_ASSIGN_0x659270")
G.add_node("AST_NODE_LEAF_0x659310")
G.add_edge("AST_NODE_ASSIGN_0x659270", "AST_NODE_LEAF_0x659310")
G.add_node("AST_NODE_EXPR_0x6593b0")
G.add_edge("AST_NODE_ASSIGN_0x659270", "AST_NODE_EXPR_0x6593b0")
G.add_node("AST_NODE_SIMPLESTMT_0x659e50")
G.add_node("AST_NODE_ASSIGN_0x659ef0")
G.add_edge("AST_NODE_SIMPLESTMT_0x659e50", "AST_NODE_ASSIGN_0x659ef0")
G.add_node("AST_NODE_STATEMENT_0x65aa30")
G.add_node("AST_NODE_SIMPLESTMT_0x65aad0")
G.add_edge("AST_NODE_STATEMENT_0x65aa30", "AST_NODE_SIMPLESTMT_0x65aad0")
G.add_node("AST_NODE_STATEMENT_0x65bc50")
G.add_edge("AST_NODE_STATEMENT_0x65aa30", "AST_NODE_STATEMENT_0x65bc50")
G.add_node("AST_NODE_LEAF_0x6561b0")
G.add_node("AST_NODE_LEAF_0x6567f0")
G.add_node("AST_NODE_IDLIST_0x656a70")
G.add_node("AST_NODE_LEAF_0x656b10")
G.add_edge("AST_NODE_IDLIST_0x656a70", "AST_NODE_LEAF_0x656b10")
G.add_node("AST_NODE_LEAF_0x656bb0")
G.add_node("AST_NODE_IO_0x656cf0")
G.add_node("AST_NODE_LEAF_0x656d90")
G.add_edge("AST_NODE_IO_0x656cf0", "AST_NODE_LEAF_0x656d90")
G.add_node("AST_NODE_STATEMENT_0x656e30")
G.add_node("AST_NODE_SIMPLESTMT_0x656ed0")
G.add_edge("AST_NODE_STATEMENT_0x656e30", "AST_NODE_SIMPLESTMT_0x656ed0")
G.add_node("AST_NODE_STATEMENT_0x6571f0")
G.add_edge("AST_NODE_STATEMENT_0x656e30", "AST_NODE_STATEMENT_0x6571f0")
G.add_node("AST_NODE_LEAF_0x659310")
G.add_node("AST_NODE_EXPR_0x6593b0")
G.add_node("AST_NODE_UNARY_0x659450")
G.add_edge("AST_NODE_EXPR_0x6593b0", "AST_NODE_UNARY_0x659450")
G.add_node("AST_NODE_ASSIGN_0x659ef0")
G.add_node("AST_NODE_LEAF_0x659f90")
G.add_edge("AST_NODE_ASSIGN_0x659ef0", "AST_NODE_LEAF_0x659f90")
G.add_node("AST_NODE_EXPR_0x65a030")
G.add_edge("AST_NODE_ASSIGN_0x659ef0", "AST_NODE_EXPR_0x65a030")
G.add_node("AST_NODE_SIMPLESTMT_0x65aad0")
G.add_node("AST_NODE_ASSIGN_0x65ab70")
G.add_edge("AST_NODE_SIMPLESTMT_0x65aad0", "AST_NODE_ASSIGN_0x65ab70")
G.add_node("AST_NODE_STATEMENT_0x65bc50")
G.add_node("AST_NODE_SIMPLESTMT_0x65bcf0")
G.add_edge("AST_NODE_STATEMENT_0x65bc50", "AST_NODE_SIMPLESTMT_0x65bcf0")
G.add_node("AST_NODE_STATEMENT_0x65cf10")
G.add_edge("AST_NODE_STATEMENT_0x65bc50", "AST_NODE_STATEMENT_0x65cf10")
G.add_node("AST_NODE_LEAF_0x656b10")
G.add_node("AST_NODE_LEAF_0x656d90")
G.add_node("AST_NODE_SIMPLESTMT_0x656ed0")
G.add_node("AST_NODE_ASSIGN_0x656f70")
G.add_edge("AST_NODE_SIMPLESTMT_0x656ed0", "AST_NODE_ASSIGN_0x656f70")
G.add_node("AST_NODE_STATEMENT_0x6571f0")
G.add_node("AST_NODE_SIMPLESTMT_0x657290")
G.add_edge("AST_NODE_STATEMENT_0x6571f0", "AST_NODE_SIMPLESTMT_0x657290")
G.add_node("AST_NODE_STATEMENT_0x6576f0")
G.add_edge("AST_NODE_STATEMENT_0x6571f0", "AST_NODE_STATEMENT_0x6576f0")
G.add_node("AST_NODE_UNARY_0x659450")
G.add_node("AST_NODE_LEAF_0x6594f0")
G.add_edge("AST_NODE_UNARY_0x659450", "AST_NODE_LEAF_0x6594f0")
G.add_node("AST_NODE_AOBEXPR_0x659950")
G.add_edge("AST_NODE_UNARY_0x659450", "AST_NODE_AOBEXPR_0x659950")
G.add_node("AST_NODE_LEAF_0x659f90")
G.add_node("AST_NODE_EXPR_0x65a030")
G.add_node("AST_NODE_AOBEXPR_0x65a850")
G.add_edge("AST_NODE_EXPR_0x65a030", "AST_NODE_AOBEXPR_0x65a850")
G.add_node("AST_NODE_ASSIGN_0x65ab70")
G.add_node("AST_NODE_LEAF_0x65ac10")
G.add_edge("AST_NODE_ASSIGN_0x65ab70", "AST_NODE_LEAF_0x65ac10")
G.add_node("AST_NODE_EXPR_0x65acb0")
G.add_edge("AST_NODE_ASSIGN_0x65ab70", "AST_NODE_EXPR_0x65acb0")
G.add_node("AST_NODE_SIMPLESTMT_0x65bcf0")
G.add_node("AST_NODE_ASSIGN_0x65bd90")
G.add_edge("AST_NODE_SIMPLESTMT_0x65bcf0", "AST_NODE_ASSIGN_0x65bd90")
G.add_node("AST_NODE_STATEMENT_0x65cf10")
G.add_node("AST_NODE_IO_0x65cfb0")
G.add_edge("AST_NODE_STATEMENT_0x65cf10", "AST_NODE_IO_0x65cfb0")
G.add_node("AST_NODE_ASSIGN_0x656f70")
G.add_node("AST_NODE_LEAF_0x657010")
G.add_edge("AST_NODE_ASSIGN_0x656f70", "AST_NODE_LEAF_0x657010")
G.add_node("AST_NODE_EXPR_0x6570b0")
G.add_edge("AST_NODE_ASSIGN_0x656f70", "AST_NODE_EXPR_0x6570b0")
G.add_node("AST_NODE_SIMPLESTMT_0x657290")
G.add_node("AST_NODE_ASSIGN_0x657330")
G.add_edge("AST_NODE_SIMPLESTMT_0x657290", "AST_NODE_ASSIGN_0x657330")
G.add_node("AST_NODE_STATEMENT_0x6576f0")
G.add_node("AST_NODE_SIMPLESTMT_0x657790")
G.add_edge("AST_NODE_STATEMENT_0x6576f0", "AST_NODE_SIMPLESTMT_0x657790")
G.add_node("AST_NODE_LEAF_0x6594f0")
G.add_node("AST_NODE_AOBEXPR_0x659950")
G.add_node("AST_NODE_AOBEXPR_0x6596d0")
G.add_edge("AST_NODE_AOBEXPR_0x659950", "AST_NODE_AOBEXPR_0x6596d0")
G.add_node("AST_NODE_LEAF_0x6599f0")
G.add_edge("AST_NODE_AOBEXPR_0x659950", "AST_NODE_LEAF_0x6599f0")
G.add_node("AST_NODE_AOBEXPR_0x659bd0")
G.add_edge("AST_NODE_AOBEXPR_0x659950", "AST_NODE_AOBEXPR_0x659bd0")
G.add_node("AST_NODE_AOBEXPR_0x65a850")
G.add_node("AST_NODE_AOBEXPR_0x65a670")
G.add_edge("AST_NODE_AOBEXPR_0x65a850", "AST_NODE_AOBEXPR_0x65a670")
G.add_node("AST_NODE_LEAF_0x65a8f0")
G.add_edge("AST_NODE_AOBEXPR_0x65a850", "AST_NODE_LEAF_0x65a8f0")
G.add_node("AST_NODE_LEAF_0x65a990")
G.add_edge("AST_NODE_AOBEXPR_0x65a850", "AST_NODE_LEAF_0x65a990")
G.add_node("AST_NODE_LEAF_0x65ac10")
G.add_node("AST_NODE_EXPR_0x65acb0")
G.add_node("AST_NODE_AOBEXPR_0x65ba70")
G.add_edge("AST_NODE_EXPR_0x65acb0", "AST_NODE_AOBEXPR_0x65ba70")
G.add_node("AST_NODE_ASSIGN_0x65bd90")
G.add_node("AST_NODE_LEAF_0x65be30")
G.add_edge("AST_NODE_ASSIGN_0x65bd90", "AST_NODE_LEAF_0x65be30")
G.add_node("AST_NODE_EXPR_0x65bed0")
G.add_edge("AST_NODE_ASSIGN_0x65bd90", "AST_NODE_EXPR_0x65bed0")
G.add_node("AST_NODE_IO_0x65cfb0")
G.add_node("AST_NODE_VARIDNUM_0x65d050")
G.add_edge("AST_NODE_IO_0x65cfb0", "AST_NODE_VARIDNUM_0x65d050")
G.add_node("AST_NODE_LEAF_0x657010")
G.add_node("AST_NODE_EXPR_0x6570b0")
G.add_node("AST_NODE_LEAF_0x657150")
G.add_edge("AST_NODE_EXPR_0x6570b0", "AST_NODE_LEAF_0x657150")
G.add_node("AST_NODE_ASSIGN_0x657330")
G.add_node("AST_NODE_LEAF_0x6573d0")
G.add_edge("AST_NODE_ASSIGN_0x657330", "AST_NODE_LEAF_0x6573d0")
G.add_node("AST_NODE_EXPR_0x657470")
G.add_edge("AST_NODE_ASSIGN_0x657330", "AST_NODE_EXPR_0x657470")
G.add_node("AST_NODE_SIMPLESTMT_0x657790")
G.add_node("AST_NODE_MODULEREUSE_0x657830")
G.add_edge("AST_NODE_SIMPLESTMT_0x657790", "AST_NODE_MODULEREUSE_0x657830")
G.add_node("AST_NODE_AOBEXPR_0x6596d0")
G.add_node("AST_NODE_VARIDNUM_0x659590")
G.add_edge("AST_NODE_AOBEXPR_0x6596d0", "AST_NODE_VARIDNUM_0x659590")
G.add_node("AST_NODE_LEAF_0x659770")
G.add_edge("AST_NODE_AOBEXPR_0x6596d0", "AST_NODE_LEAF_0x659770")
G.add_node("AST_NODE_VARIDNUM_0x659810")
G.add_edge("AST_NODE_AOBEXPR_0x6596d0", "AST_NODE_VARIDNUM_0x659810")
G.add_node("AST_NODE_LEAF_0x6599f0")
G.add_node("AST_NODE_AOBEXPR_0x659bd0")
G.add_node("AST_NODE_VARIDNUM_0x659a90")
G.add_edge("AST_NODE_AOBEXPR_0x659bd0", "AST_NODE_VARIDNUM_0x659a90")
G.add_node("AST_NODE_LEAF_0x659c70")
G.add_edge("AST_NODE_AOBEXPR_0x659bd0", "AST_NODE_LEAF_0x659c70")
G.add_node("AST_NODE_LEAF_0x659d10")
G.add_edge("AST_NODE_AOBEXPR_0x659bd0", "AST_NODE_LEAF_0x659d10")
G.add_node("AST_NODE_AOBEXPR_0x65a670")
G.add_node("AST_NODE_AOBEXPR_0x65a490")
G.add_edge("AST_NODE_AOBEXPR_0x65a670", "AST_NODE_AOBEXPR_0x65a490")
G.add_node("AST_NODE_LEAF_0x65a710")
G.add_edge("AST_NODE_AOBEXPR_0x65a670", "AST_NODE_LEAF_0x65a710")
G.add_node("AST_NODE_LEAF_0x65a7b0")
G.add_edge("AST_NODE_AOBEXPR_0x65a670", "AST_NODE_LEAF_0x65a7b0")
G.add_node("AST_NODE_LEAF_0x65a8f0")
G.add_node("AST_NODE_LEAF_0x65a990")
G.add_node("AST_NODE_AOBEXPR_0x65ba70")
G.add_node("AST_NODE_AOBEXPR_0x65b610")
G.add_edge("AST_NODE_AOBEXPR_0x65ba70", "AST_NODE_AOBEXPR_0x65b610")
G.add_node("AST_NODE_LEAF_0x65bb10")
G.add_edge("AST_NODE_AOBEXPR_0x65ba70", "AST_NODE_LEAF_0x65bb10")
G.add_node("AST_NODE_LEAF_0x65bbb0")
G.add_edge("AST_NODE_AOBEXPR_0x65ba70", "AST_NODE_LEAF_0x65bbb0")
G.add_node("AST_NODE_LEAF_0x65be30")
G.add_node("AST_NODE_EXPR_0x65bed0")
G.add_node("AST_NODE_AOBEXPR_0x65c510")
G.add_edge("AST_NODE_EXPR_0x65bed0", "AST_NODE_AOBEXPR_0x65c510")
G.add_node("AST_NODE_VARIDNUM_0x65d050")
G.add_node("AST_NODE_LEAF_0x65d0f0")
G.add_edge("AST_NODE_VARIDNUM_0x65d050", "AST_NODE_LEAF_0x65d0f0")
G.add_node("AST_NODE_LEAF_0x657150")
G.add_node("AST_NODE_LEAF_0x6573d0")
G.add_node("AST_NODE_EXPR_0x657470")
G.add_node("AST_NODE_UNARY_0x657510")
G.add_edge("AST_NODE_EXPR_0x657470", "AST_NODE_UNARY_0x657510")
G.add_node("AST_NODE_MODULEREUSE_0x657830")
G.add_node("AST_NODE_IDLIST_0x6578d0")
G.add_edge("AST_NODE_MODULEREUSE_0x657830", "AST_NODE_IDLIST_0x6578d0")
G.add_node("AST_NODE_LEAF_0x657c90")
G.add_edge("AST_NODE_MODULEREUSE_0x657830", "AST_NODE_LEAF_0x657c90")
G.add_node("AST_NODE_IDLIST_0x657d30")
G.add_edge("AST_NODE_MODULEREUSE_0x657830", "AST_NODE_IDLIST_0x657d30")
G.add_node("AST_NODE_VARIDNUM_0x659590")
G.add_node("AST_NODE_LEAF_0x659630")
G.add_edge("AST_NODE_VARIDNUM_0x659590", "AST_NODE_LEAF_0x659630")
G.add_node("AST_NODE_LEAF_0x659770")
G.add_node("AST_NODE_VARIDNUM_0x659810")
G.add_node("AST_NODE_LEAF_0x6598b0")
G.add_edge("AST_NODE_VARIDNUM_0x659810", "AST_NODE_LEAF_0x6598b0")
G.add_node("AST_NODE_VARIDNUM_0x659a90")
G.add_node("AST_NODE_LEAF_0x659b30")
G.add_edge("AST_NODE_VARIDNUM_0x659a90", "AST_NODE_LEAF_0x659b30")
G.add_node("AST_NODE_LEAF_0x659c70")
G.add_node("AST_NODE_LEAF_0x659d10")
G.add_node("AST_NODE_AOBEXPR_0x65a490")
G.add_node("AST_NODE_AOBEXPR_0x65a210")
G.add_edge("AST_NODE_AOBEXPR_0x65a490", "AST_NODE_AOBEXPR_0x65a210")
G.add_node("AST_NODE_LEAF_0x65a530")
G.add_edge("AST_NODE_AOBEXPR_0x65a490", "AST_NODE_LEAF_0x65a530")
G.add_node("AST_NODE_LEAF_0x65a5d0")
G.add_edge("AST_NODE_AOBEXPR_0x65a490", "AST_NODE_LEAF_0x65a5d0")
G.add_node("AST_NODE_LEAF_0x65a710")
G.add_node("AST_NODE_LEAF_0x65a7b0")
G.add_node("AST_NODE_AOBEXPR_0x65b610")
G.add_node("AST_NODE_AOBEXPR_0x65b110")
G.add_edge("AST_NODE_AOBEXPR_0x65b610", "AST_NODE_AOBEXPR_0x65b110")
G.add_node("AST_NODE_LEAF_0x65b6b0")
G.add_edge("AST_NODE_AOBEXPR_0x65b610", "AST_NODE_LEAF_0x65b6b0")
G.add_node("AST_NODE_AOBEXPR_0x65b890")
G.add_edge("AST_NODE_AOBEXPR_0x65b610", "AST_NODE_AOBEXPR_0x65b890")
G.add_node("AST_NODE_LEAF_0x65bb10")
G.add_node("AST_NODE_LEAF_0x65bbb0")
G.add_node("AST_NODE_AOBEXPR_0x65c510")
G.add_node("AST_NODE_AOBEXPR_0x65c010")
G.add_edge("AST_NODE_AOBEXPR_0x65c510", "AST_NODE_AOBEXPR_0x65c010")
G.add_node("AST_NODE_LEAF_0x65c5b0")
G.add_edge("AST_NODE_AOBEXPR_0x65c510", "AST_NODE_LEAF_0x65c5b0")
G.add_node("AST_NODE_AOBEXPR_0x65ca10")
G.add_edge("AST_NODE_AOBEXPR_0x65c510", "AST_NODE_AOBEXPR_0x65ca10")
G.add_node("AST_NODE_LEAF_0x65d0f0")
G.add_node("AST_NODE_UNARY_0x657510")
G.add_node("AST_NODE_LEAF_0x6575b0")
G.add_edge("AST_NODE_UNARY_0x657510", "AST_NODE_LEAF_0x6575b0")
G.add_node("AST_NODE_LEAF_0x657650")
G.add_edge("AST_NODE_UNARY_0x657510", "AST_NODE_LEAF_0x657650")
G.add_node("AST_NODE_IDLIST_0x6578d0")
G.add_node("AST_NODE_LEAF_0x657970")
G.add_edge("AST_NODE_IDLIST_0x6578d0", "AST_NODE_LEAF_0x657970")
G.add_node("AST_NODE_IDLIST_0x657a10")
G.add_edge("AST_NODE_IDLIST_0x6578d0", "AST_NODE_IDLIST_0x657a10")
G.add_node("AST_NODE_LEAF_0x657c90")
G.add_node("AST_NODE_IDLIST_0x657d30")
G.add_node("AST_NODE_LEAF_0x657dd0")
G.add_edge("AST_NODE_IDLIST_0x657d30", "AST_NODE_LEAF_0x657dd0")
G.add_node("AST_NODE_IDLIST_0x657e70")
G.add_edge("AST_NODE_IDLIST_0x657d30", "AST_NODE_IDLIST_0x657e70")
G.add_node("AST_NODE_LEAF_0x659630")
G.add_node("AST_NODE_LEAF_0x6598b0")
G.add_node("AST_NODE_LEAF_0x659b30")
G.add_node("AST_NODE_AOBEXPR_0x65a210")
G.add_node("AST_NODE_VARIDNUM_0x65a0d0")
G.add_edge("AST_NODE_AOBEXPR_0x65a210", "AST_NODE_VARIDNUM_0x65a0d0")
G.add_node("AST_NODE_LEAF_0x65a2b0")
G.add_edge("AST_NODE_AOBEXPR_0x65a210", "AST_NODE_LEAF_0x65a2b0")
G.add_node("AST_NODE_VARIDNUM_0x65a350")
G.add_edge("AST_NODE_AOBEXPR_0x65a210", "AST_NODE_VARIDNUM_0x65a350")
G.add_node("AST_NODE_LEAF_0x65a530")
G.add_node("AST_NODE_LEAF_0x65a5d0")
G.add_node("AST_NODE_AOBEXPR_0x65b110")
G.add_node("AST_NODE_AOBEXPR_0x65ae90")
G.add_edge("AST_NODE_AOBEXPR_0x65b110", "AST_NODE_AOBEXPR_0x65ae90")
G.add_node("AST_NODE_LEAF_0x65b1b0")
G.add_edge("AST_NODE_AOBEXPR_0x65b110", "AST_NODE_LEAF_0x65b1b0")
G.add_node("AST_NODE_AOBEXPR_0x65b390")
G.add_edge("AST_NODE_AOBEXPR_0x65b110", "AST_NODE_AOBEXPR_0x65b390")
G.add_node("AST_NODE_LEAF_0x65b6b0")
G.add_node("AST_NODE_AOBEXPR_0x65b890")
G.add_node("AST_NODE_VARIDNUM_0x65b750")
G.add_edge("AST_NODE_AOBEXPR_0x65b890", "AST_NODE_VARIDNUM_0x65b750")
G.add_node("AST_NODE_LEAF_0x65b930")
G.add_edge("AST_NODE_AOBEXPR_0x65b890", "AST_NODE_LEAF_0x65b930")
G.add_node("AST_NODE_LEAF_0x65b9d0")
G.add_edge("AST_NODE_AOBEXPR_0x65b890", "AST_NODE_LEAF_0x65b9d0")
G.add_node("AST_NODE_AOBEXPR_0x65c010")
G.add_node("AST_NODE_LEAF_0x65bf70")
G.add_edge("AST_NODE_AOBEXPR_0x65c010", "AST_NODE_LEAF_0x65bf70")
G.add_node("AST_NODE_LEAF_0x65c0b0")
G.add_edge("AST_NODE_AOBEXPR_0x65c010", "AST_NODE_LEAF_0x65c0b0")
G.add_node("AST_NODE_AOBEXPR_0x65c290")
G.add_edge("AST_NODE_AOBEXPR_0x65c010", "AST_NODE_AOBEXPR_0x65c290")
G.add_node("AST_NODE_LEAF_0x65c5b0")
G.add_node("AST_NODE_AOBEXPR_0x65ca10")
G.add_node("AST_NODE_AOBEXPR_0x65c790")
G.add_edge("AST_NODE_AOBEXPR_0x65ca10", "AST_NODE_AOBEXPR_0x65c790")
G.add_node("AST_NODE_LEAF_0x65cab0")
G.add_edge("AST_NODE_AOBEXPR_0x65ca10", "AST_NODE_LEAF_0x65cab0")
G.add_node("AST_NODE_AOBEXPR_0x65cc90")
G.add_edge("AST_NODE_AOBEXPR_0x65ca10", "AST_NODE_AOBEXPR_0x65cc90")
G.add_node("AST_NODE_LEAF_0x6575b0")
G.add_node("AST_NODE_LEAF_0x657650")
G.add_node("AST_NODE_LEAF_0x657970")
G.add_node("AST_NODE_IDLIST_0x657a10")
G.add_node("AST_NODE_LEAF_0x657ab0")
G.add_edge("AST_NODE_IDLIST_0x657a10", "AST_NODE_LEAF_0x657ab0")
G.add_node("AST_NODE_IDLIST_0x657b50")
G.add_edge("AST_NODE_IDLIST_0x657a10", "AST_NODE_IDLIST_0x657b50")
G.add_node("AST_NODE_LEAF_0x657dd0")
G.add_node("AST_NODE_IDLIST_0x657e70")
G.add_node("AST_NODE_LEAF_0x657f10")
G.add_edge("AST_NODE_IDLIST_0x657e70", "AST_NODE_LEAF_0x657f10")
G.add_node("AST_NODE_IDLIST_0x657fb0")
G.add_edge("AST_NODE_IDLIST_0x657e70", "AST_NODE_IDLIST_0x657fb0")
G.add_node("AST_NODE_VARIDNUM_0x65a0d0")
G.add_node("AST_NODE_LEAF_0x65a170")
G.add_edge("AST_NODE_VARIDNUM_0x65a0d0", "AST_NODE_LEAF_0x65a170")
G.add_node("AST_NODE_LEAF_0x65a2b0")
G.add_node("AST_NODE_VARIDNUM_0x65a350")
G.add_node("AST_NODE_LEAF_0x65a3f0")
G.add_edge("AST_NODE_VARIDNUM_0x65a350", "AST_NODE_LEAF_0x65a3f0")
G.add_node("AST_NODE_AOBEXPR_0x65ae90")
G.add_node("AST_NODE_VARIDNUM_0x65ad50")
G.add_edge("AST_NODE_AOBEXPR_0x65ae90", "AST_NODE_VARIDNUM_0x65ad50")
G.add_node("AST_NODE_LEAF_0x65af30")
G.add_edge("AST_NODE_AOBEXPR_0x65ae90", "AST_NODE_LEAF_0x65af30")
G.add_node("AST_NODE_VARIDNUM_0x65afd0")
G.add_edge("AST_NODE_AOBEXPR_0x65ae90", "AST_NODE_VARIDNUM_0x65afd0")
G.add_node("AST_NODE_LEAF_0x65b1b0")
G.add_node("AST_NODE_AOBEXPR_0x65b390")
G.add_node("AST_NODE_VARIDNUM_0x65b250")
G.add_edge("AST_NODE_AOBEXPR_0x65b390", "AST_NODE_VARIDNUM_0x65b250")
G.add_node("AST_NODE_LEAF_0x65b430")
G.add_edge("AST_NODE_AOBEXPR_0x65b390", "AST_NODE_LEAF_0x65b430")
G.add_node("AST_NODE_VARIDNUM_0x65b4d0")
G.add_edge("AST_NODE_AOBEXPR_0x65b390", "AST_NODE_VARIDNUM_0x65b4d0")
G.add_node("AST_NODE_VARIDNUM_0x65b750")
G.add_node("AST_NODE_LEAF_0x65b7f0")
G.add_edge("AST_NODE_VARIDNUM_0x65b750", "AST_NODE_LEAF_0x65b7f0")
G.add_node("AST_NODE_LEAF_0x65b930")
G.add_node("AST_NODE_LEAF_0x65b9d0")
G.add_node("AST_NODE_LEAF_0x65bf70")
G.add_node("AST_NODE_LEAF_0x65c0b0")
G.add_node("AST_NODE_AOBEXPR_0x65c290")
G.add_node("AST_NODE_VARIDNUM_0x65c150")
G.add_edge("AST_NODE_AOBEXPR_0x65c290", "AST_NODE_VARIDNUM_0x65c150")
G.add_node("AST_NODE_LEAF_0x65c330")
G.add_edge("AST_NODE_AOBEXPR_0x65c290", "AST_NODE_LEAF_0x65c330")
G.add_node("AST_NODE_VARIDNUM_0x65c3d0")
G.add_edge("AST_NODE_AOBEXPR_0x65c290", "AST_NODE_VARIDNUM_0x65c3d0")
G.add_node("AST_NODE_AOBEXPR_0x65c790")
G.add_node("AST_NODE_VARIDNUM_0x65c650")
G.add_edge("AST_NODE_AOBEXPR_0x65c790", "AST_NODE_VARIDNUM_0x65c650")
G.add_node("AST_NODE_LEAF_0x65c830")
G.add_edge("AST_NODE_AOBEXPR_0x65c790", "AST_NODE_LEAF_0x65c830")
G.add_node("AST_NODE_VARIDNUM_0x65c8d0")
G.add_edge("AST_NODE_AOBEXPR_0x65c790", "AST_NODE_VARIDNUM_0x65c8d0")
G.add_node("AST_NODE_LEAF_0x65cab0")
G.add_node("AST_NODE_AOBEXPR_0x65cc90")
G.add_node("AST_NODE_VARIDNUM_0x65cb50")
G.add_edge("AST_NODE_AOBEXPR_0x65cc90", "AST_NODE_VARIDNUM_0x65cb50")
G.add_node("AST_NODE_LEAF_0x65cd30")
G.add_edge("AST_NODE_AOBEXPR_0x65cc90", "AST_NODE_LEAF_0x65cd30")
G.add_node("AST_NODE_VARIDNUM_0x65cdd0")
G.add_edge("AST_NODE_AOBEXPR_0x65cc90", "AST_NODE_VARIDNUM_0x65cdd0")
G.add_node("AST_NODE_LEAF_0x657ab0")
G.add_node("AST_NODE_IDLIST_0x657b50")
G.add_node("AST_NODE_LEAF_0x657bf0")
G.add_edge("AST_NODE_IDLIST_0x657b50", "AST_NODE_LEAF_0x657bf0")
G.add_node("AST_NODE_LEAF_0x657f10")
G.add_node("AST_NODE_IDLIST_0x657fb0")
G.add_node("AST_NODE_LEAF_0x658050")
G.add_edge("AST_NODE_IDLIST_0x657fb0", "AST_NODE_LEAF_0x658050")
G.add_node("AST_NODE_LEAF_0x65a170")
G.add_node("AST_NODE_LEAF_0x65a3f0")
G.add_node("AST_NODE_VARIDNUM_0x65ad50")
G.add_node("AST_NODE_LEAF_0x65adf0")
G.add_edge("AST_NODE_VARIDNUM_0x65ad50", "AST_NODE_LEAF_0x65adf0")
G.add_node("AST_NODE_LEAF_0x65af30")
G.add_node("AST_NODE_VARIDNUM_0x65afd0")
G.add_node("AST_NODE_LEAF_0x65b070")
G.add_edge("AST_NODE_VARIDNUM_0x65afd0", "AST_NODE_LEAF_0x65b070")
G.add_node("AST_NODE_VARIDNUM_0x65b250")
G.add_node("AST_NODE_LEAF_0x65b2f0")
G.add_edge("AST_NODE_VARIDNUM_0x65b250", "AST_NODE_LEAF_0x65b2f0")
G.add_node("AST_NODE_LEAF_0x65b430")
G.add_node("AST_NODE_VARIDNUM_0x65b4d0")
G.add_node("AST_NODE_LEAF_0x65b570")
G.add_edge("AST_NODE_VARIDNUM_0x65b4d0", "AST_NODE_LEAF_0x65b570")
G.add_node("AST_NODE_LEAF_0x65b7f0")
G.add_node("AST_NODE_VARIDNUM_0x65c150")
G.add_node("AST_NODE_LEAF_0x65c1f0")
G.add_edge("AST_NODE_VARIDNUM_0x65c150", "AST_NODE_LEAF_0x65c1f0")
G.add_node("AST_NODE_LEAF_0x65c330")
G.add_node("AST_NODE_VARIDNUM_0x65c3d0")
G.add_node("AST_NODE_LEAF_0x65c470")
G.add_edge("AST_NODE_VARIDNUM_0x65c3d0", "AST_NODE_LEAF_0x65c470")
G.add_node("AST_NODE_VARIDNUM_0x65c650")
G.add_node("AST_NODE_LEAF_0x65c6f0")
G.add_edge("AST_NODE_VARIDNUM_0x65c650", "AST_NODE_LEAF_0x65c6f0")
G.add_node("AST_NODE_LEAF_0x65c830")
G.add_node("AST_NODE_VARIDNUM_0x65c8d0")
G.add_node("AST_NODE_LEAF_0x65c970")
G.add_edge("AST_NODE_VARIDNUM_0x65c8d0", "AST_NODE_LEAF_0x65c970")
G.add_node("AST_NODE_VARIDNUM_0x65cb50")
G.add_node("AST_NODE_LEAF_0x65cbf0")
G.add_edge("AST_NODE_VARIDNUM_0x65cb50", "AST_NODE_LEAF_0x65cbf0")
G.add_node("AST_NODE_LEAF_0x65cd30")
G.add_node("AST_NODE_VARIDNUM_0x65cdd0")
G.add_node("AST_NODE_LEAF_0x65ce70")
G.add_edge("AST_NODE_VARIDNUM_0x65cdd0", "AST_NODE_LEAF_0x65ce70")
G.add_node("AST_NODE_LEAF_0x657bf0")
G.add_node("AST_NODE_LEAF_0x658050")
G.add_node("AST_NODE_LEAF_0x65adf0")
G.add_node("AST_NODE_LEAF_0x65b070")
G.add_node("AST_NODE_LEAF_0x65b2f0")
G.add_node("AST_NODE_LEAF_0x65b570")
G.add_node("AST_NODE_LEAF_0x65c1f0")
G.add_node("AST_NODE_LEAF_0x65c470")
G.add_node("AST_NODE_LEAF_0x65c6f0")
G.add_node("AST_NODE_LEAF_0x65c970")
G.add_node("AST_NODE_LEAF_0x65cbf0")
G.add_node("AST_NODE_LEAF_0x65ce70")



#nx.draw(G, with_labels = True)
#plt.show()

nx.nx_agraph.write_dot(G,'test.dot')
plt.title('draw_networkx')
pos=graphviz_layout(G, prog='dot')
nx.draw(G, pos, with_labels=False, arrows=False)
plt.show()
#plt.savefig('nx_test.png')