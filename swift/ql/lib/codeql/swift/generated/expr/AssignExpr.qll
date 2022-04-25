// generated by codegen/codegen.py
import codeql.swift.elements.expr.Expr

class AssignExprBase extends @assign_expr, Expr {
  override string toString() { result = "AssignExpr" }

  Expr getDest() {
    exists(Expr x |
      assign_exprs(this, x, _) and
      result = x.resolve()
    )
  }

  Expr getSource() {
    exists(Expr x |
      assign_exprs(this, _, x) and
      result = x.resolve()
    )
  }
}
