from datetime import datetime

from flask import Flask, request, jsonify

import constants
from email_utils import token_store

app = Flask(__name__)


@app.route("/wificonnections/approve", methods=["GET"])
def approve():
    token = request.args.get("token")

    token_data = token_store.get(token)
    if not token_data:
        return jsonify({"error": "Invalid or expired token"}), 400

    if datetime.utcnow() > token_data[constants.store_key_expires_at]:
        del token_store[token]
        return jsonify({"error": "Token has expired"}), 400

    user_email = token_data[constants.store_key_email]
    user_mac_id = token_data[constants.store_key_mac_id]

    del token_store[token]
    # TODO: add to whitelist
    return jsonify({"message": f"Approval successful for {user_email} ({user_mac_id})"}), 200


if __name__ == "__main__":
    app.run(debug=True)
