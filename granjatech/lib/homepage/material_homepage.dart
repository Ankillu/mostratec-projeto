import 'package:flutter/material.dart';

class MyMaterialHomePage extends StatelessWidget {
  const MyMaterialHomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Macumba"),
      ),
      body: const Center(
        child: Text("Texto"),
      ),
    );
  }
}
